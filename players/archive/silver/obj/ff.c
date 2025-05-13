/*
  Coded by Silver 30-03-95
*/

#pragma strict_types
#pragma save_types

inherit "/obj/thing";

 string fname;
 string *allfile,*line;
 int num_lin;


int _more_this_room()
 {
  fname=file_name(environment(this_player()));
  fname="/"+fname+".c";
  write(fname+"\n");
  this_player()->more_string(read_file(fname));
  return 1;
 }


int _read_file()
 {
  int i;
  fname=file_name(environment(this_player()));
  fname="/"+fname+".c";
  allfile=explode(read_file(fname),"\n");
  num_lin=sizeof(allfile)-1;
  write(" Number of lines " + num_lin + "\n");
  return 1;
 }

int _add_actions()
 {
   int i;
   string q,w,e,r,t,y,fun,act,garb;

  fname=file_name(environment(this_player()));
  fname="/"+fname+".c";
  allfile=explode(read_file(fname),"\n");
   for(i=0;i<sizeof(allfile)-1;i++)
    {
if(sscanf(allfile[i],"%sadd_action(%s\"%s\"%s,%s\"%s\"%s\)%s",
   q,w,fun,e,r,act,t,y)>0)
    {
        write("Add_action found : " + act + " --> " + fun + "\n" );
       }
      else
       {
if(sscanf(allfile[i],"%sAA(%s\"%s\"%s,%s\"%s\"%s\)%s",
   q,w,fun,e,r,act,t,y)>0)
         write("Add_action found : " + act + " --> " + fun + "\n" );
       }
    }
   return 1;
 }

void reset(int arg)
 {
  ::reset(arg);
  if(arg) return;
  set_name("ft");
  set_short("ft");
  set_long("commands :  here ... more source of this room          \n"+
           "            rf   ... read file need to be done before  \n"+
           "                     functions  bellow are called      \n"+
           "            add  ... gives list of add_action          \n"
          );
  set_weight(0);
 }

void init()
 {
  ::init();
  add_action("_read_file","rf");
  add_action("_more_this_room","here");
  add_action("_add_actions","add");
 }
