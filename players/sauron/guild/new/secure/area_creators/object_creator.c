#include "/players/sauron/guild/include/functions.c"

#define DEF_PATH		"/players/sauron/guild/areas"

#define DEF_INHERIT		"inherit \"/obj/treasure\";\n"
#define DEF_RESET1		"void reset(int arg) {\n"
#define DEF_RESET2		"  ::reset(arg);\n"
#define DEF_RESET3		"  if(!arg) {\n"
#define DEF_INDENT		"    "
#define DEF_END1		"  }\n"
#define DEF_END2		"}\n"

#define MAX_SHORT_LENGTH	40
#define MAX_LONG_LENGTH		75

mapping path,file,name,alias,alt_name,short,long,value,weight,read,info,output;

string display_file() {
  string ret,*tmp;
  int i;

  ret="";
  tmp=output[TP];

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

  write("\nThank you for using Sauron's object creator.\nIf you need to add \
anything more to your object, ");
  if(NEW(TP))
    write("I'm afraid you'll have to do it by hand.\n");
  else
    write("I'm afraid you'll have to get Sauron to do it.\n");
}

void display_current() {
  printf("Ok, so far, '%s%s' looks like this:\n\n%s\n",
         APPR(TP)?path[TP]:"",file[TP],display_file());
}

void abort() {
  write("\nAborting..\n");
  output[TP]=0;
}

void get_weight(string str) {
  int weight;

  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_weight");
    return;
  }
  else if(!str || !sscanf(str,"%d",weight)) {
    write("That wouldn't make a very good weight. Try again.\n] ");
    input_to("get_weight");
    return;
  }
  else {
    output[TP]+=({DEF_INDENT+"set_weight("+weight+");\n"});
/*
    write("\nOk, now enter any read info for the object.\n] ");
    input_to("get_read");
*/
    finish();
    return;
  }
}

void get_value(string str) {
  int value;

  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_value");
    return;
  }
  else if(!str || !sscanf(str,"%d",value)) {
    write("That wouldn't make a very good value. Try again.\n] ");
    input_to("get_value");
    return;
  }
  else {
    output[TP]+=({DEF_INDENT+"set_value("+value+");\n"});
    write("\nOk, now enter the object's weight.\n] ");
    input_to("get_weight");
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

void get_long(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_long");
    return;
  }
  else if(!str || str=="") {
    write("] ");
    input_to("get_long");
    return;
  }
  else if(str=="**") {
    if(long[TP]=="\\\n")
      long[TP]=short[TP]+"\\n";
    else
      long[TP]=long[TP][0..<4]+"\\n";
    output[TP]+=({DEF_INDENT+"set_long(\""+long[TP]+"\");\n"});
    write("\nOk, now enter the object's value.\n] ");
    input_to("get_value");
    return; 
  }
  else if(strlen(str)>MAX_LONG_LENGTH) {
    printf("I told you that lines longer than %d chars would be \
rejected. Try again.\n  <%s>\n] ",MAX_LONG_LENGTH,
sprintf("%|'-'*s",(MAX_LONG_LENGTH-2),"-"));
    input_to("get_long");
    return;
  }
  else {
    long[TP]+=test_line(str);
    long[TP]+=" \\\n";   
    write("] ");
    input_to("get_long");
    return;
  }
}

void get_short(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_short");
    return;
  }
  else if(!str || str=="") {
    write("That would make an interesting description. Try again.\n] ");
    input_to("get_short");
    return;
  }
  else if(str=="**")
    return get_short(name[TP]);
  else if(strlen(str)>MAX_SHORT_LENGTH) {
    write("That sounds more like a LONG description. Try again.\n] ");
    input_to("get_short");
    return;
  }
  else {
    if(str[<1..<1]!=".")
      str+=".";
    short[TP]=str;
    output[TP]+=({DEF_INDENT+"set_short(\""+test_line(str)+"\");\n"});
    printf("\nOk, now enter a long description. Enter ** on a blank line \
to stop.\nIf no description is given, \"%s\\n\" will be used.\nNote: \
lines longer than %d chars will be rejected.\n  <%s>\n] ",
           str,MAX_LONG_LENGTH,sprintf("%|'-'*s",(MAX_LONG_LENGTH-2),"-"));
    input_to("get_long");
    return;
  }
}

void get_alt_name(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_alt_name");
    return;
  }
  else if(!str || str=="") {
    write("That would make an interesting alt_name. Try again.\n] ");
    input_to("get_alt_name");
    return;
  }
  else if(str=="**") {
    printf("\nOk, now enter a short description for '%s'.\nIf no \
description is given, \"%s.\" will be used.\n] ",file[TP],name[TP]);
    input_to("get_short");
    return;
  }
  else {
    output[TP]+=({DEF_INDENT+"set_alt_name(\""+str+"\");\n"});
    printf("\nOk, now enter a short description for '%s'.\nIf no \
description is given, \"%s.\" will be used.\n] ",file[TP],name[TP]);
    input_to("get_short");
    return;
  }
}

void get_alias(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_alias");
    return;
  }
  else if(!str || str=="") {
    write("That would make an interesting alias. Try again.\n] ");
    input_to("get_alias");
    return;
  }
  else if(str=="**") {
    printf("\nOk, now enter an alt_name for '%s'.\n] ",file[TP]);
    input_to("get_alt_name");
    return;
  }
  else {
    output[TP]+=({DEF_INDENT+"set_alias(\""+str+"\");\n"});
    printf("\nOk, now enter an alt_name for '%s'.\n] ",file[TP]);
    input_to("get_alt_name");
    display_current();
    return;
  }
}

void get_name(string str) {
  if(str && str=="~q") {
    abort();
    return;
  }
  else if(str && str=="~d") {
    display_current();
    write("] ");
    input_to("get_name");
    return;
  }
  else if(!str || str=="") {
    write("That would make an interesting name. Try again.\n] ");
    input_to("get_name");
    return;
  }
  else if(str=="**") {
    printf("You have to give '%s' a name.\n] ",file[TP]);
    input_to("get_name");
    return;
  }
  else {
    name[TP]=str;
    output[TP]+=({DEF_INDENT+"set_name(\""+str+"\");\n"});
    printf("\nOk, now enter an alias for '%s'.\n] ",file[TP]);
    input_to("get_alias");
    return;
  }
}

void main(string str) {
  if(!str || str=="") {
    write("You must specify the file_name of the object you want to \
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
    if(file_size(DEF_PATH+"/"+RNAME(TP)+"/obj")==-1)
      mkdir(DEF_PATH+"/"+RNAME(TP)+"/obj");
    path[TP]=DEF_PATH+"/"+RNAME(TP)+"/obj";
  }
  else {
    write("You don't have security clearance to use the object creator.\n");
    return;
  }

  path[TP]+="/";

  if(file_size(path[TP]+file[TP])!=-1) {
    printf("'%s' already exists...\n",file[TP]);
    return;
  }

  printf("\nInitialising variables for object '%s'",file[TP]);
  long[TP]="\\\n";
  output[TP]=({});
  output[TP]+=({DEF_INHERIT});
  output[TP]+=({"\n"});
  output[TP]+=({DEF_RESET1});
  output[TP]+=({DEF_RESET2});
  output[TP]+=({DEF_RESET3});
  write(".\n");

  write("\nEnter '~q' at any prompt to abort object creation.\n");
  write("Enter '~d' at any prompt to display the current code.\n");
  write("Enter '**' to skip entering a value and move on.\n");
  printf("\nPlease enter a name for '%s'.\n] ",file[TP]);
  input_to("get_name");
  return;
}

void reset(int arg) {
  if(!arg) {
    path=([]);
    file=([]);
    name=([]);
    short=([]);
    long=([]);
    read=([]);
    info=([]);
    output=([]);
  }
}
