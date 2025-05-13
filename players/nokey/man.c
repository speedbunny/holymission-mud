void more_string(string str);
#define CHUNK 16
#define MR_INTRO "More: (u/d/q) line: "
#define MR_EXTRO "*"

#define MANTOPICS ({"build","coding","lfun","efun","w","LPC","examples","ORIGS","races","rules"})

int id(string s)
  {
  return s=="pager" || s=="man pager" || s=="man" || s=="manual pager";
  }

int _man(string what) {
    string help_file_str, help_file_name;
    string *topics;
    mixed mantopic;
    int tcount;
    mantopic=MANTOPICS;
    if(!what)
      {
      write("There are manual entries on the following subtopics:\n");
      for(tcount=0; tcount<(sizeof(mantopic)-1); tcount++)
        write(mantopic[tcount] +", ");
      write(mantopic[sizeof(mantopic)-1] +".\n");
      return 1;
      }
    if(sizeof(topics = explode(what," ")) >2)
      {
      notify_fail("You can only put one space in a manual topic.\n");
      return 0;
      }
    if(sizeof(topics)==2)
      {
      if( help_file_str = read_file("/doc/"+topics[0]+"/"+topics[1]))
        {
        help_file_str ="** Manual entry from /doc/"+ 
        topics[0] +"/"+ topics[1] +" **\n"+ help_file_str;
        more_string(help_file_str);
        return 1;
        }
      notify_fail("No manual entry for "+ topics[1] +" under "+ topics[0]
      +".\n");
      return 0;
      }
    if(member_array(what,MANTOPICS)+1)
      {
      mixed help_file_names;
      int a;
      help_file_names = get_dir("/doc/"+ what +"/");
      help_file_str="The subject "+ what +" has the following topics:\n";
      for(a=0; a<sizeof(help_file_names); a++)
        {
        help_file_str+=sprintf("%-24s\t",help_file_names[a]);
        if(a &&!((a+1)%2)) help_file_str+="\n";
        }
      more_string(help_file_str);
      return 1;
      }
    for(tcount=0; tcount<sizeof(mantopic); tcount++)
      if( help_file_str = read_file(help_file_name =
      "/doc/"+ mantopic[tcount] +"/"+ what)) break;
    if(help_file_str)
      {
      help_file_str ="** Manual entry from "+ help_file_name +" **\n"+
      help_file_str;
      more_string(help_file_str);
      return 1;
      }
    else
      {
      notify_fail("No manual entry on that topic.\n");
      return 0;
      }
}
void init()
  {
  add_action("_man","man");
  }

int get()
  { return 1; }

string short()
  { return "A manual pager"; }

void long()
  {
  write("a manual pager.\nCommand: man <options> "+
  "where <options> can be:\nnone\n<topic>\n<maintopic> <subtopic>\n");
  }

static void more_help(string str,string *help_file,int line) {
int a,helpline,max;

  helpline=line;
  if (str == "d" || str == "") helpline+=16;
  if(str=="q") {
    write("Ok.\n");
    return;
  }
  if (str == "u") helpline -=16;
  if (helpline < 0) helpline = 0;
  max=sizeof(help_file);
  for(a=helpline;a<helpline+CHUNK;a++) {
    if(a==max) {
      write("End.\n");
      return;
    }
    write(help_file[a] +"\n");
    }
  write(MR_INTRO+(a+1)+MR_EXTRO);
  input_to("more_help",0,help_file,helpline);
  }

void more_string(string str) {
  more_help(" ",explode(str,"\n"),0);
}

