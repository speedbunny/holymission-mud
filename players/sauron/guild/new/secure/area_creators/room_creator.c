#include "/players/sauron/guild/include/functions.c"

#define DEF_PATH		"/players/sauron/guild/areas"

#define DEF_INHERIT		"inherit \"/room/room\";\n"
#define DEF_RESET1		"void reset(int arg) {\n"
#define DEF_RESET2		"  ::reset(arg);\n"
#define DEF_RESET3		"  if(!arg) {\n"
#define DEF_INDENT		"    "
#define DEF_REPLACE		"    replace_program(\"/room/room\");\n"
#define DEF_END1		"  }\n"
#define DEF_END2		"}\n"

#define MAX_SHORT_LENGTH	40
#define MAX_LONG_LENGTH		75

mapping path,file,short_desc,long_desc,dir,item,dest_dir,items,output;

string display_file() {
  string ret,*tmp;
  int i;

  ret="";
  tmp=output[TP];

  tmp+=({DEF_REPLACE});
  tmp+=({DEF_END1});
  tmp+=({DEF_END2});

  for(i=0;i<sizeof(tmp);i++)
    ret+=tmp[i];

  return ret;
}

void finish() {
  string ret;

  ret=display_file();

  printf("\nOk, the final version of '%s%s' looks like this:\n\n%s\n\n",
         APPR(TP)?path[TP]:"",file[TP],ret);

  write_file(path[TP]+file[TP],ret);

  write("\nThank you for using Sauron's room creator.\nIf you need to add \
anything more to your room, ");
  if(NEW(TP))
    write("I'm afraid you'll have to do it by hand.\n");
  else
    write("I'm afraid you'll have to get Sauron to do it.\n");
}

void display_current() {
  printf("\nOk, so far, '%s%s' looks like this:\n\n%s\n\n",
         APPR(TP)?path[TP]:"",file[TP],display_file());
}

void abort() {
  write("\nAborting...\n");
  output[TP]=0;
}

void get_item2(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_item2");
    return;
  }
  else if(!str || str=="") {
    write("All items have descriptions. Try again.\n] ");
    input_to("get_item2");
    return;
  }
  else if(str=="**") {
    printf("You have to enter a description for the item '%s' first.\n] ",
           item);
    input_to("get_item2");
    return;
  }
  else {
    items[TP]+=({item[TP],str});
    write("\nOk, now enter the room's next item, or ** to finish your \
room and write it to a file.\n] ");
    input_to("get_item1");
    return;
  }
}

void get_item1(string str) {
  int i,sz;

  sz=sizeof(items[TP]);

  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_item1");
    return;
  }
  else if(!str || str=="") {
    write("That won't make a good item. Try again.\n] ");
    input_to("get_item1");
    return;
  }
  else if(member_array(str,items[TP])!=-1) {
    write("You already have that item. Try again.\n] ");
    input_to("get_item1");
    return;
  }
  else if(str=="**") {
    output[TP]+=({DEF_INDENT+"items=({\n"});
    for(i=0;i<sz;i+=2)
      output[TP]+=({DEF_INDENT+"  \""+items[TP][i]+"\",\""
                                     +items[TP][i+1]+"\",\n"});
    output[TP]+=({DEF_INDENT+"});\n"});

    finish();
    return;
  }
  else {
    item[TP]=str;
    printf("\nOk, now enter a description for '%s'.\n] ",str);
    input_to("get_item2");
    return;
  }
}

void get_dest_dir2(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_dest_dir2");
    return;
  }
  else if(!str || str=="") {
    write("You can't make an exit that doesn't go anywhere. Try again.\n] ");
    input_to("get_dest_dir2");
    return;
  }
  else if(str=="**") {
    printf("You have to enter a file for the exit '%s' first.\n] ",dir);
    input_to("get_dest_dir2");
    return;
  }
  else if(str[0..1]=="$$") {
    dest_dir[TP]+=({str,dir[TP]});
    write("\nOk, now enter the room's next exit, or ** to move on to the \
items.\n] ");
    input_to("get_dest_dir1");
    return;
  }
  else {
    if(!NEW(TP))
      str=explode(str,"/")[<1];
    if(str[0..0]!="/")
      str=path[TP]+str;
    sscanf(str,"%s.c",str);
    dest_dir[TP]+=({str,dir[TP]});
    write("\nOk, now enter the room's next exit, or ** to move on to the \
items.\n] ");
    input_to("get_dest_dir1");
    return;
  }
}

void get_dest_dir1(string str) {
  int i,sz;

  sz=sizeof(dest_dir[TP]);

  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_dest_dir1");
    return;
  }
  else if(!str || str=="") {
    write("That won't make a good exit. Try again.\n] ");
    input_to("get_dest_dir1");
    return;
  }
  else if(member_array(str,dest_dir[TP])!=-1) {
    write("You already have that exit. Try again.\n] ");
    input_to("get_dest_dir1");
    return;
  }
  else if(str=="**") {
    output[TP]+=({DEF_INDENT+"dest_dir=({\n"});
    for(i=0;i<sz;i+=2)
      output[TP]+=({DEF_INDENT+"  \""+dest_dir[TP][i]+"\",\""
                                     +dest_dir[TP][i+1]+"\",\n"});
    output[TP]+=({DEF_INDENT+"});\n"});
    write("\nOk, now enter the room's first item (eg \"tree\").\n] ");
    input_to("get_item1");
    return;
  }
  else {
    dir[TP]=str;
    printf("\nOk, now enter the %sname of the room that the exit '%s' \
leads to%s] ",NEW(TP)?"file_":"",str,NEW(TP)?".\nYour current path will \
be prepended if the file_name doesn't begin with a '/'.\n":" (eg \
'room2').\nIf you want this file to lead somewhere other than to a room \
in your area, enter '$$<where>' here (eg '$$church').\n");
    input_to("get_dest_dir2");
    return;
  }
}

status line_filter(string str) {
  return (str && str!="");
}

string test_line(string line) {
  string *lines;

  line=implode(explode(line,"\\n")," ");
  line=implode(explode(line,"\\t")," ");

  while(line[0..0]==" " || line[0..0]=="\t")
    line=line[1..<1];
  while(line[<1..<1]==" " || line[<1..<1]=="\t")
    line=line[0..<2];

  lines=explode(line," ");
  lines=filter_array(lines,"line_filter",TO);
  line=implode(lines," ");

  return line;
}

void get_long_desc(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_long_desc");
    return;
  }
  else if(!str || str=="") {
    write("] ");
    input_to("get_long_desc");
    return;
  }
  else if(str=="**") {
    if(long_desc[TP]=="\\\n")
      long_desc[TP]=short_desc[TP]+"\\n";
    else
      long_desc[TP]=long_desc[TP][0..<4]+"\\n";
    output[TP]+=({DEF_INDENT+"long_desc=\""+long_desc[TP]+"\";\n"});
    write("\nOk, now enter the room's first exit (eg \"north\").\n] ");
    input_to("get_dest_dir1");
    return;
  }
  else if(strlen(str)>MAX_LONG_LENGTH) {
    printf("I told you that lines longer than %d chars would be \
rejected. Try again.\n  <%s>\n] ",MAX_LONG_LENGTH,
sprintf("%|'-'*s",(MAX_LONG_LENGTH-2),"-"));
    input_to("get_long_desc");
    return;
  }
  else {
    long_desc[TP]+=test_line(str);
    long_desc[TP]+=" \\\n";
    write("] ");
    input_to("get_long_desc");
    return;
  }
}

void get_short_desc(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_short_desc");
    return;
  }
  else if(!str || str=="") {
    write("That would make an interesting description. Try again.\n] ");
    input_to("get_short_desc");
    return;
  }
  else if(strlen(str)>MAX_SHORT_LENGTH) {
    write("That sounds more like a LONG description. Try again.\n] ");
    input_to("get_short_desc");
    return;
  }
  else {
    if(str[<1..<1]!=".")
      str+=".";
    short_desc[TP]=str;
    output[TP]+=({DEF_INDENT+"short_desc=\""+test_line(str)+"\";\n"});
    printf("\nOk, now enter a long description. Enter ** on a blank line \
to stop.\nIf no description is given, \"%s\\n\" will be used.\nNote: \
lines longer than %d chars will be rejected.\n  <%s>\n] ",
           str,MAX_LONG_LENGTH,sprintf("%|'-'*s",(MAX_LONG_LENGTH-2),"-"));
    input_to("get_long_desc");
    return;
  }
}

void get_light_level(string str) {
  int light;

  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_light_level");
    return;
  }
  else if(!str || !sscanf(str,"%d",light)) {
    write("That wouldn't make a very good light level. Try again.\n] ");
    input_to("get_light_level");
    return;
  }
  else {
    output[TP]+=({DEF_INDENT+"set_light("+light+");\n"});
    printf("\nOk, now enter the short description for '%s' (%d chars \
maximum).\n] ",file[TP],MAX_SHORT_LENGTH);
    input_to("get_short_desc");
    return;
  }
}

void main(string str) {
  if(!str || str=="") {
    write("You must specify the file_name of the room you want to \
create.\n");
    return;
  }

  if(str[<2..<1]!=".c")
    file[TP]=str+".c";
  else
    file[TP]=str;

  if(NEW(TP)) {
    file[TP]=expand_filename(file[TP]);
    path[TP]=implode(explode(file[TP],"/")[0..<2],"/");
    file[TP]=explode(file[TP],"/")[<1];
  }
  else if(query_protector(TP,1)) {
    if(file_size(DEF_PATH)==-1)
      mkdir(DEF_PATH);
    if(file_size(DEF_PATH+"/"+RNAME(TP))==-1)
      mkdir(DEF_PATH+"/"+RNAME(TP));
    if(file_size(DEF_PATH+"/"+RNAME(TP)+"/rooms")==-1)
      mkdir(DEF_PATH+"/"+RNAME(TP)+"/rooms");
    path[TP]=DEF_PATH+"/"+RNAME(TP)+"/rooms";
  }
  else {
    write("You don't have security clearance to use the room creator.\n");
    return;
  }

  path[TP]+="/";

  if(file_size(path[TP]+file[TP])!=-1) {
    printf("'%s' already exists...\n",file[TP]);
    return;
  }

  printf("\nInitialising variables for room '%s'",file[TP]);
  long_desc[TP]="\\\n";
  dest_dir[TP]=({});
  items[TP]=({});
  output[TP]=({});
  output[TP]+=({DEF_INHERIT});
  output[TP]+=({"\n"});
  output[TP]+=({DEF_RESET1});
  output[TP]+=({DEF_RESET2});
  output[TP]+=({DEF_RESET3});
  write(".\n");

  write("\nEnter '~q' at any prompt to abort room creation.\n");
  write("Enter '~d' at any prompt to display the current code.\n");
  printf("\nPlease enter the light level for '%s'.\n] ",file[TP]);
  input_to("get_light_level");
  return;
}

void reset(int arg) {
  if(!arg) {
    path=([]);
    file=([]);
    short_desc=([]);
    long_desc=([]);
    dir=([]);
    item=([]);
    dest_dir=([]);
    items=([]);
    output=([]);
  }
}
