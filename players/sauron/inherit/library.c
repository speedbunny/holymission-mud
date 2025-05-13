// Generic Library File.					Author: Sauron
//								Date: 220197

inherit "/room/room";

#include <lw.h>

static string library;	// This is the path for the library files.
mapping selections;	// A mapping to record the books people are reading.

void fix_dir() {
  if(!library)
    return;
  if(library[0..0]!="/")
    library="/"+library;
  if(library[<1..<1]!="/")
    library+="/";
}

int order(string str1,string str2) {
  int i1,i2;

  sscanf(str1,"%d_%*s",i1);
  sscanf(str2,"%d_%*s",i2);

  return i1<i2;
}

varargs int filter(string str,string base,int flag) {
  if(flag)
    return file_size(base+str)>=0;
  else
    return file_size(base+str)==-2;
}

string list(string *arr) {
  string ret;
  int j,i;

  j=sizeof(arr);
  switch(j) {
    case 0:
      return "\n";
      break;
    case 1:
      return sprintf("%s.\n",arr[0]);
      break;
    case 2:
      return sprintf("%s and %s.\n",arr[0],arr[1]);
      break;
    default:
      ret="";
      for(i=0;i<j-2;i++)
	ret+=arr[i]+", ";
      ret+=arr[<2]+" and "+arr[<1]+".\n";
      return ret;
      break;
  }
}

int _browse(string str) {
  string ret;
  int i,sz;

  if(!str) {
    string *catagories;

    catagories=get_dir(library+".");
    catagories=filter_array(catagories,"filter",this_object(),library);
    catagories=sort_array(catagories,#'>);
    sz=sizeof(catagories);
    for(i=0;i<sz;i++)
      catagories[i]=capitalize(catagories[i]);
    if(sizeof(catagories))
      ret="You browse through the library and find sections on the \
following subjects:\n\n"+list(catagories);
    else
      ret="Hmm odd - this library doesn't have any sections!\n";
    write(ret);
    return 1;
  }

  else if(file_size(library+str)!=-2) {
    notify_fail("No such catagory found in the library.\n");
    return 0;
  }

  else {
    string *books;

    books=get_dir(library+str+"/.");
    books=filter_array(books,"filter",this_object(),library+str+"/");
    books=sort_array(books,#'>);
    sz=sizeof(books);
    for(i=0;i<sz;i++)
      books[i]=capitalize(books[i]);
    if(sizeof(books))
      ret="You browse through the '"+capitalize(str)
         +"' section and find the following books:\n\n"+list(books);
    else
      ret="The '"+capitalize(str)
         +"' section doesn't contain any books right now.\n";
    write(ret);
    return 1;
  }
}

int _select(string str) {
  string catagory,book;
  string *catagories;

  catagories=get_dir(library+".");
  catagories=filter_array(catagories,"filter",this_object(),library);

  if(!str) {
    notify_fail("Which book do you wish to select?\n");
    return 0;
  }
  else if(sscanf(str,"%s:%s",catagory,book)==2) {
    catagory=lower_case(catagory);
    book=lower_case(book);

    if(member_array(catagory,catagories)==-1) {
      notify_fail("No such section found in the library.\n");
      return 0;
    }
    else if(file_size(library+catagory+"/"+book)!=-2) {
      notify_fail("No such book found in the '"+capitalize(catagory)
                 +"' section.\n");
      return 0;
    }
    else {
      selections[this_player()]=library+catagory+"/"+book+"/";
      write("You select a book entitled '"+capitalize(book)+"' from the "
            +capitalize(catagory)+" section of the library.\n");
      return 1;
    }
  }
  else {
    string *books;
    int i,sz;

    book=catagory=(string)0;
    sz=sizeof(catagories);
    str=lower_case(str);

    for(i=0;i<sz;i++) {
      books=get_dir(library+catagories[i]+"/.");
      if(member_array(str,books)!=-1) {
        catagory=catagories[i];
        book=str;
        break;
      }
      else
        continue;
    }
    if(book) {
      selections[this_player()]=library+catagory+"/"+book+"/";
      write("You select a book entitled '"+capitalize(book)+"' from the '"
            +capitalize(catagory)+"' section of the library.\n");
      return 1;
    }
    else {
      notify_fail("No such book found in the library.\n");
      return 0;
    }
  }
}

int _read(string str) {
  string book,ret,*arr,file,chapter_name,chapter_num;
  int i;
  object tp;
  mapping index;

  index=([]);

  if(!(tp=this_player()))
    return 0;

  else
    book=selections[tp];

  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  else if(!book) {
    notify_fail("You haven't selected a book from the library yet.\n");
    return 0;
  }
  else {
    string *chapters;

    chapters=get_dir(book+".");
    chapters=filter_array(chapters,"filter",this_object(),book,1);
    chapters=sort_array(chapters,"order",this_object());
    for(i=0;i<sizeof(chapters);i++) {
      arr=explode(chapters[i],"_");
      index[arr[0]]=lower_case(arr[1]);
    }
    str=lower_case(str);
  }

  if(str=="index") {
    string shrt_bk;
 
    shrt_bk=capitalize(explode(book,"/")[<2]);
    arr=m_indices(index);
    if(sizeof(arr)) {
      ret="The book '"+shrt_bk+"' has the following chapters:\n\n";

      for(i=0;i<sizeof(arr);i++) {
        ret=sprintf("%s%3s. %s\n",ret,arr[i],capitalize(index[arr[i]]));
      }
    }
    else
      ret="The book '"+shrt_bk+"' does't have any chapters.\n";

    tp->more_string(ret);
    return 1;
  }
  else if((i=member_array(str,m_values(index)))!=-1) {
    arr=m_indices(index);
    chapter_name=str;
    chapter_num=arr[i];
  }
  else if((i=member_array(str,m_indices(index)))!=-1) {
    arr=m_values(index);
    chapter_name=arr[i];
    chapter_num=str;
  }
  else {
    notify_fail("No such chapter found in the book '"+shrt_bk+"'.\n");
    return 0;
  }
  file=read_file(book+chapter_num+"_"+chapter_name);
  ret="You read chapter "+chapter_num+": '"+capitalize(chapter_name)
     +"'.\n\n";
  if(!file || file=="")
    ret+="Odd - this chapter appears to be empty.\n";
  else
    ret+=lw(file);

  tp->more_string(ret);
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    selections=([]);
  }
}

void init() {
  ::init();

  fix_dir();	// Make sure that the library dir set at reset() is formatted.

  if(library) {
    add_action("_browse","browse");
    add_action("_select","select");
    add_action("_read",  "read");
  }
}
