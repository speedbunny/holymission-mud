/*
 * Author      : Galadriel.
 * Date        : 03-10-1992.
 * Last update : 05-09-1993.
 * (c) YSY-SYS, the Netherlands.
 *

|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|This tool is created by Yke Syb Ykema better known as Galadriel@Holy Mission.|
|Since there are months of development and some original ideas in it, I think |
|it is reasonable to claim the full copyright for myself as the author of it. |
|Therefore you may not copy this work. Not to another dir, not to another mud,|
|not download it, not to anywhere (not even to another universe). (c) YSY-SYS |
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Well, what _is_ permitted then?
The arches of Holy Mission may read it and use it freely.
It is still under construction so it _will_ have bugs. I will be happy with
any bugreports but I don't feel responsible for any trouble the bugs cause ;)

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
definitions:

area: all rooms that have their files in one dir.
this area: the area that is being mapped.
outer area: rooms that don't have their files in the dir of this area.
nodes: GIS technology word, here it's some data for one room.
  data for one room: filename, coordinates, coordinate type.
    coordinate type: invalid, unknown, local, area, world.
half arc: (GIS) refs to two nodes and direction from first to second node.
full arc: (GIS) refs to two nodes, two directions and data for arc.
  data for arc: arctype.
    arctype: two way, oneway, secret, inconsistant, etc.

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
what it can do:

- find the dir path of the area you are standing in.
- find the dir paths of the areas its connected to.
- find all nodes in this area.
- find the nodes in outer area that connect to this area.
- find all half arcs starting in the found nodes in this dir.
- find the half arc starting in outer area and leading to nodes in this dir.
- find the full arcs that connect the nodes in this area.
- find the full arcs that connect this area to outer areas.
- set the local coordinates of your environment at zero.
- find the coordinates of all nodes that connect with arcs to nodes with
  known coordinates.
- display a map of this area on the screen.
- write a map of this area to a file.
- check for missing files.
- check for inconsistant full arcs.
- use a master file for this area. (zero node, user defined arcs)
  use interface for masterfile.

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
what it can _not_ do:

- check for hidden destinations.
- check for move_player.
- check for other types of move.
- use a store file for this area. (store map info)
- divide the map of this area in parts that fit the width of screen or printer.
- change the maxwidth of the map parts.

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ok, now for the code, have fun:
 */

#define NODEBUG_MODE    0
#define DEBUG_MODE      1

#define INVALID_COORDS -1
#define UNKNOWN_COORDS  0
#define LOCAL_COORDS	1
/* future ideas etc.*/
#define AREA_COORDS	2
#define WORLD_COORDS	3

#define INVALID_ARC    -1
#define UNKNOWN_ARC	0
#define TWO_WAY_ARC	1
#define ONE_WAY_ARC	2
#define SPECIAL_ARC	3

/* future ideas etc.*/
#define NO_FILE_ARC    -3
#define BAD_FILE_ARC   -2
#define SECRET1_ARC	4
#define SECRET2_ARC	5
#define TRAPPED1_ARC	6
#define TELEPORT_ARC	7

/* area data */
string *list_no_exits,*list_paths,*files;
mixed *list_nodes,*list_arcs,*list_full_arcs,*ok_arcs,*list_arc_lengths;
int *index_nodes;
int area_loaded,coords,                               /* set by mirror.  */
    screen_width,mode,maxff,maxnn,maxaa,node_width,   /* set by user.    */
    f,a,n,maxf,maxn,                                  /* global counters.*/
    x,y,z,minx,miny,minz,maxx,maxy,maxz;              /* coordinates.    */
string map,arcline;

id (str) { return str=="mirror of Galadriel" || str=="mirror" ; }

short   () { return "Mirror of Galadriel (v3.6)"; }

long   ()  { write
  ("This is the Mirror of Galadriel. Any mortal looking in it will die . . .\n");
}

reset(arg) {
  if (arg) return;
  area_loaded=0;
  screen_width=79;
  node_width=10;
  maxff=6;
  maxaa=12;
  maxnn=8;
  mode=DEBUG_MODE;
  ok_arcs=({ ({ "north"    , "south"    ,  0, -1,  0 }),
             ({ "south"    , "north"    ,  0,  1,  0 }),
             ({ "west"     , "east"     , -1,  0,  0 }),
             ({ "east"     , "west"     ,  1,  0,  0 }),
             ({ "up"       , "down"     ,  0,  0,  1 }),
             ({ "down"     , "up"       ,  0,  0, -1 }),
             ({ "northwest", "southeast", -1, -1,  0 }),
             ({ "southeast", "northwest",  1,  1,  0 }),
             ({ "northeast", "southwest",  1, -1,  0 }),
             ({ "southwest", "northeast", -1,  1,  0 }) });
}

init   () {
  add_action("do_look_in","look");
  add_action("do_conc","mc");
  add_action("do_quick_map","mq");
  add_action("do_scan_environment","mh");
  add_action("tmp_scan_area","ms");
  add_action("do_dump","ml");
  add_action("lib_file_map","mf");
  add_action("do_set_maxff","maxfiles");
  add_action("do_set_maxaa","maxarcs");
  add_action("do_set_maxnn","maxnodes");
  add_action("do_set_screenwidth","mscreenwidth");
  add_action("do_set_nodewidth","mnodewidth");
  add_action("do_set_mode","mirrormode");
  add_action("do_mirror_status","mstat");
  add_action("lib_dest_call_out","mstop");
  add_action("do_conc_hard","conchard");
  add_action("do_send","sendmirror");

  add_action("lib_init_lists","ms1");
  add_action("lib_scan_files","ms2");
  add_action("lib_get_files","ms2a");
  add_action("lib_scan_file","ms2b");
  add_action("lib_create_full_arcs","ms3");
  add_action("lib_find_coordinates","ms4");
  add_action("lib_index_nodes","ms5");
  add_action("lib_max_coord","ms6");
  add_action("lib_create_map","ms7");
  add_action("lib_display_map","ms8");
}

int do_set_mode(string arg) {
  if(!arg) {
    write("The mirror shows 'debug' and 'nodebug'\n");
    return 1;
  }
  switch (arg) {
    case "debug"   : mode=DEBUG_MODE; break;
    case "nodebug" : mode=NODEBUG_MODE;
                     write("The mirror shows the word '"+arg+"'\n");
                     break;
    default : write ("The mirror shows a big '?'\n"); break;
  }
  return 1;
}

int do_set_maxff(int arg) {
  if(!arg)
    write("The Mirror displays a chunk consisting of "+maxff+" files.\n");
  else {
    maxff=(int)arg;
    write("The Mirror swirls violently and the image of a chunk changes to "+
          maxff+" files.\n");
  }
  return 1;
}

int do_set_maxaa(int arg) {
  if(!arg)
    write("The Mirror displays a chunk consisting of "+maxaa+" half arcs.\n");
  else {
    maxaa=(int)arg;
    write("The Mirror swirls violently and the image of a chunk changes to "+
          maxaa+" half arcs.\n");
  }
  return 1;
}

int do_set_maxnn(int arg) {
  if(!arg)
    write("The Mirror displays a chunk consisting of "+maxnn+" nodes.\n");
  else {
    maxnn=(int)arg;
    write("The Mirror swirls violently and the image of a chunk changes to "+
          maxnn+" nodes.\n");
  }
  return 1;
}

int do_set_nodewidth(int arg) {
  if(!arg)
    write("The Mirror displays a node consisting of "+node_width+" chars.\n");
  else {
    node_width=(int)arg;
    write("The Mirror swirls violently and the image of a node changes to "+
          node_width+" chars.\n");
  }
  return 1;
}

int do_set_screenwidth(int arg) {
  if(!arg)
    write("The Mirror displays a screenline of "+screen_width+" chars.\n");
  else {
    screen_width=(int)arg;
    write("The Mirror swirls violently and the screenline changes to "+
          screen_width+" chars.\n");
  }
  return 1;
}

int do_look_in(string arg) {
  if (arg!="in mirror")
    return 0;
  if (!this_player()->query_archwiz()) {
    write("Your fast decision not to look in it saves you from dying...\n");
    write("This Mirror is for arches only! (Well at least for now)\n");
    return 1;
  }
  printf(""+
        "mq : mirror quick maps\n"+
        "mh : mirror here\n"+
        "ms : mirror scan\n"+
        "ml : mirror list\n"+
        "mf : mirror file map\n"+
        "maxfiles, maxarcs, maxnodes, mnodewidth, mirrormode,\n"+
        "mstat, mstop\n"+
        "");
  return 1;
}

int do_mirror_status() {
  
/*
string *list_no_exits,*list_paths,*files;
mixed *list_nodes,*list_arcs,*list_full_arcs,*ok_arcs;
int *index_nodes;
int area_loaded,
    mode,maxff,maxnn,maxaa,node_width,
    f,a,n,maxf,maxn,
    x,y,z,minx,miny,minz,maxx,maxy,maxz;
string map;
*/
  printf("%-*.2#s\n",screen_width,
    "vars\n\n"+
    "maxfiles\n"+
    "maxnodes\n"+
    "maxarcs\n"+
    "   values\n\n"+
    "== "+(string)maxff+"\n"+
    "== "+(string)maxnn+"\n"+
    "== "+(string)maxaa
/*  printf("%-15=s %-60=s\n",screen_width-15,
    "vars"+
    "maxfiles"+
    "maxnodes"+
    "maxarcs",
    "   values"+
    "== "+(string)maxff+
    "== "+(string)maxnn+
    "== "+(string)maxaa*/
  );
  return 1;
}

get   ()  { return 1; }  /* no get */
drop   () { return 1; }
query_auto_load   ()   { return "players/haplo/misc/tools/mirror:";}

ladjust(str,n) { return extract(str + "                             ",0,n-1); }

do_conc(string   str) {
  string who;
  object inv;
  int i,j,nrfound;
string fn,tmp;

  nrfound = 0;
  who = users();
  for (i = 0; i < sizeof(who); i++) {
    if (who[i]->short())
      write(ladjust(who[i]->query_real_name(),16) + " ");
    else write(ladjust("(" + who[i]->query_real_name() + ")",16) + " ");
    write(ladjust(who[i]->query_level(),5) + " " +
          ladjust(who[i]->query_money(),11) + "\n");
    if (who[i]->query_level() < 31) {
      inv=deep_inventory(who[i]);
      for(j=0;j<sizeof(inv);j++) {
        if ((inv[j]->short()==str) ||
            (inv[j]->query_name()==str) ||
            (inv[j]->id(str))) {
        nrfound++;
        write("  ");
	fn=file_name(inv[j]);
	if(!sscanf(fn,"players/%s",tmp))   write(fn);
	else   write("~" + tmp);
          if(environment(inv[j])!=who[i]) {
             write(" in ");
            fn=file_name(environment(inv[j]));
            if(!sscanf(fn,"players/%s",tmp)) write(fn);
            else write("~" + tmp);
          }
          write(" \t");
          if(!inv[j]->short()) {
             if(inv[j]->query_name()) write("("+inv[j]->query_name()+")");
             else write("(unknown)");
          } else write(inv[j]->short());
          write("\n");
        }
      }
    write("\n");
    }
  }
  write(nrfound +" instances of "+ str +" found.\n");
  return 1;
}

do_send(who) {
  object mirror, pl;
  if (this_player()->query_real_name()!="galadriel") return;
  if (!who) return;
  pl=find_living(who);
  if (!pl) return;
  if (!(pl->query_level()>29 || pl->query_testchar())) {
    write ("Give your mirror to players???\n"); return 1; }
  mirror=(transfer(clone_object("players/galadriel/library/mirror"),pl));
  return 1;
}

do_conc_hard(string   str) {
  string who;
  object inv;
  int i,j;
string fn,tmp;

  who = users();
  for (i = 0; i < sizeof(who); i++) {
    if (who[i]->short())
      write(ladjust(who[i]->query_real_name(),16) + " ");
    else write(ladjust("(" + who[i]->query_real_name() + ")",16) + " ");
    write(ladjust(who[i]->query_level(),5) + " " +
          ladjust(who[i]->query_money(),11) + "\n");

    inv=deep_inventory(who[i]);
    for(j=0;j<sizeof(inv);j++) {
/*
      if ((inv[j]->short()==str) ||
          (inv[j]->query_name()==str) ||
*/
      if ((inv[j]->query_name()==str) ||
          (inv[j]->id(str))) {
	    fn=file_name(inv[j]);
	    if(!sscanf(fn,"players/%s",tmp)) write(fn);
	    else write("~" + tmp);
        if(environment(inv[j])!=who[i]) {
           write(" in ");
           write(environment(inv[j]));
        }
        write(" \t");
/*
        if(!inv[j]->short()) {
*/
           if(inv[j]->query_name()) write("("+inv[j]->query_name()+")");
           else write("(unknown)");
/*
        } else write(inv[j]->short());
*/
        write("\n");
      }
    }
  }
  return 1;
}

/*---- jul-aug 1993: funcs for quick rooms && deep scanner ----*/

object lib_get_room(string file) {
  object room;

  if(file_size(file+".c")<0) {
    write("DEBUG: Mirror thinks file "+file+" does not exist\n");
    return 0;
  }
  room=find_object(file);
  if (!room) {
    if(catch(file->load_me())) {
      write("DEBUG: Mirror could not load "+file+"\n");
      return 0;
    }
    room=find_object(file);
  }
  return room;
}

/*---- jul 1993: quick room maps ----------------------------*/

string md(string direction,string *exits) {
  int i;
  i=member_array(direction,exits);
  if (i==-1)
    return (string)" ";
  else
    return (string)exits[i-1];
}

void mdx(string *exits) {
  int i,size;

  size=sizeof(exits);
  for(i=0;i<size;i+=2) {
    switch (exits[i+1]) {
      case "north"     : break;
      case "south"     : break;
      case "west"      : break;
      case "east"      : break;
      case "northwest" : break;
      case "southeast" : break;
      case "northeast" : break;
      case "southwest" : break;
      default : write("Exit "+(string)exits[i+1]+
                      " to "+(string)exits[i]+"\n"); break;
    }
  }
  return;
}

void lib_display_room(string *rooms, string herefile) {
  int rw;

  rw=18;
  printf("%*s", rw, md("northwest",rooms));       printf(" ");
  printf("%|*s", rw, md("north",rooms));          printf(" ");
  printf("%-*s", rw, md("northeast",rooms)+"\n");
  printf("%*s", rw+1, "\\");
  printf("%|*s", rw, "|");
  printf("/\n");
  printf("%*s", rw, md("west",rooms));            printf("-");
  printf("%|*s", rw, herefile);                   printf("-");
  printf("%-*s", rw, md("east",rooms)+"\n");
  printf("%*s", rw+1, "/");
  printf("%|*s", rw, "|");
  printf("\\\n");
  printf("%*s", rw, md("southwest",rooms));       printf(" ");
  printf("%|*s", rw, md("south",rooms));          printf(" ");
  printf("%-*s", rw, md("southeast",rooms)+"\n");
  mdx(rooms);
}

int lib_scan_room(string pathfile) {
  object here;
  string herefile,herepath;
  string *exits,*rooms,*tmp;
  int i,special;

  here=lib_get_room(pathfile);
  if(!here)
    return 0;
  exits=(string *)here->query_room("dest_dir");
  rooms=allocate(sizeof(exits));
  tmp=explode(pathfile,"/");
  herefile=tmp[sizeof(tmp)-1];
  tmp=del_array(tmp,sizeof(tmp)-1);
  herepath=implode(tmp,"/");
  if (herepath[0..0]!="/") herepath = "/"+herepath;
  special=0;
  for(i=0;i<sizeof(exits);i+=2) {
    string tmppath,tmpfile;
    tmp=explode(exits[i],"/");
    tmpfile=tmp[sizeof(tmp)-1];
    tmp=del_array(tmp,sizeof(tmp)-1);
    tmppath=implode(tmp,"/");
    if (tmppath[0..0]!="/") tmppath = "/"+tmppath;
    if (tmppath != herepath) {
      special++;
      tmpfile=(string)special+"/"+tmpfile;
      write(special+" == "+tmppath+"\n");
    }
    rooms[i]=tmpfile;
    rooms[i+1]=exits[i+1];
  }

  lib_display_room(rooms, herefile);

  return 1;
}

int do_scan_environment() {
  object here;
  string pathfile;

  here=environment(this_player());
  pathfile=file_name(environment(this_player()));
  write("You are in "+pathfile+".\n\n");
  lib_scan_room(pathfile);
  return 1;
}

int do_quick_map(string arg) {
  object here;
  string herepath,herefile;
  string *files;
  string *exits,*rooms,*tmp;
  int i,j,f;

  if (!this_player()->query_archwiz()) {
    write("Sorry, but it is an arch-command at the moment...\n");
    return 1;
  }
  if((!arg)||((arg!="here")&&(arg!="all"))) {
    write("mq here  : quick tiny map of the room you are in.\n"+
          "mq all   : quick tiny maps of all rooms in this area.\n"+
          "\nThese commands are _very_ limited so dont complain about them\n");
    return 1;
  }

  /* get the room we are in and its exits */
  here=environment(this_player());
  herefile=file_name(environment(this_player()));
  exits=(string *)here->query_room("dest_dir");

  /* show the filename */
  write("You are in "+herefile+".\n\n");

  if(arg=="here") {
    lib_scan_room(herefile);
    return 1;
  }
  tmp=explode(herefile,"/");
  herefile=tmp[sizeof(tmp)-1];
  tmp=del_array(tmp,sizeof(tmp)-1);
  herepath=implode(tmp,"/");
  if (herepath[0..0]!="/") herepath = "/"+herepath;
  if (herepath[-1..-1]!="/") herepath+="/";

  files=get_dir(herepath+"*.c");
  /* TO DO: get only _rooms_ ! */
  if(!(j=sizeof(files))) {
    write("The Mirror shows you an empty area...\n");
    return 1;
  }
  for(f=0;f<j;f++) {
    printf("%|'~'*s\n",56,"["+herepath+files[f]+"]");
    tmp=explode(files[f],".");
    files[f]=tmp[0];
    lib_scan_room(herepath+files[f]);
  }
  return 1;
}


/*---- sep 1993: configfile for scanner, debugger, mapper -----------*/
/* TO DO:
- at present the config file must be loaded first. The area zero point
  and the area nodes will be just added to an empty nodelist.
  no check if the nodes already existed is done!
- When it finds the coords of a node it should set the type of the new
  coords the same as the type of the old coords (if positive).
- dumpfunc for arc_lengths
- funcs for changing zero node, coords and arc lengths interactively
  then it needs to recalculate from a certain point.
- there could be a possibility to recalculate the nodes
  by substracting the LOCAL_coords of words[1] from all nodes
  there could be a var area_zero_node and a var world_anchor.
  there could be funcs local_to_area() and area_to_local(),
  and area_to_world() and world_to_area.
  another possibility is calc_world() calc_area() calc_local().
  or calc_world(node) and all_calc_world() for one or all nodes.
*/

/* This will overrule any initial LOCAL_COORDS and throw away all nodes */
void set_area_zero(string *words) {
  if(sizeof(words)!=2) { /* AREA_ZERO node */
    write("ERROR reading AREA_ZERO\n");
    return;
  }
  list_nodes = ({ ({ words[1], 0, 0, 0, AREA_COORDS }) });
  coords=AREA_COORDS;
  return;
}

/* This func will not check if node already exists! */
/* It does also not check if mirror is in areamode (coords==AREA_COORDS) */
void set_area_node(string *words) {
  if(sizeof(words)!=5) { /* AREA_NODE node x y z */
    write("ERROR reading AREA_NODE\n");
    return;
  }
  list_nodes += ({ ({ words[1], words[2], words[3], words[4], AREA_COORDS }) });
  return;
}

void set_arc_length(string *words) {
  if(sizeof(words)!=4) { /* ARC_LENGTH node1 node2 length */
    write("ERROR reading ARC_LENGTH\n");
    return;
  }
  /* TO DO: initialise arc_lengths array in lib_init_lists() */
  list_arc_lengths += ({ ({ words[1], words[2], words[3] }) });
  return;
}

void lib_read_defines() {
  string file;
  string *lines,*words;
  int size_lines,i;

  if(file_size(list_paths[0]+"AREA_DEF")<0)
    return;
  file=read_file(list_paths[0]+"AREA_DEF");
  lines=explode(file,"\n");
  size_lines=sizeof(lines);
  for(i=0;i<size_lines;i++) {
    words=explode(lines[i]," ");
    switch(words[0]) {
      case "AREA_ZERO"  : set_area_zero(words);
      case "AREA_NODE"  : set_area_node(words);
      case "ARC_LENGHT" : set_arc_length(words);
    }
  }
}

/*---- aug 1993: scanner, debugger, mapper ----------------------------*/


int lib_init_lists() {
  object here;
  string herepath,herefile;
  string *tmp;

  here=environment(this_player());
  herefile=file_name(environment(this_player()));
  write("You are in "+herefile+".\n\n");
  tmp=explode(herefile,"/");
  herefile=tmp[sizeof(tmp)-1];
  tmp=del_array(tmp,sizeof(tmp)-1);
  herepath=implode(tmp,"/");
  if (herepath[0..0]!="/")
    herepath = "/"+herepath;
  if (herepath[-1..-1]!="/")
    herepath+="/";

  list_paths = ({ herepath });
  list_nodes = ({ ({ herefile, 0, 0, 0 ,LOCAL_COORDS }) });
  coords=LOCAL_COORDS;
  list_arcs = allocate(0);
  list_full_arcs = allocate(0);
  list_no_exits = allocate(0);
  list_arc_lengths = allocate(0);
  f=0;
  a=0;
  return 1;
}

/* paths to outer area */
int lib_add_path(string path) {
  int pos;

  pos=member_array(path,list_paths);
  if (pos == -1) {
    list_paths += ({ path });
    return sizeof(list_paths)-1;
  }
  return pos;
}

/* node is room with coordinates */
int lib_add_node(string herefile) {
  int i,size,pos;

  size=sizeof(list_nodes);
  pos=-1;
  for(i=0;(i<size)&&(pos==-1);i++)
    if (list_nodes[i][0]==herefile)
      pos=i;
  if (pos==-1) {
    list_nodes += ({ ({ herefile, 0, 0, 0, UNKNOWN_COORDS }) });
    return sizeof(list_nodes)-1;
  }
  return pos;
}

/*  */
int old_lib_add_coordinates(int arc,int n1,int n2,int c1,int c2) {
  int size,pos,i,here,there;

  size=sizeof(ok_arcs);
  pos=-1;
  for(i=0;(i<size)&&(pos==-1);i++)
    if ((ok_arcs[i][0]==list_full_arcs[arc][c1])&&
        (ok_arcs[i][1]==list_full_arcs[arc][c2]))
      pos=i;
  for(i=0;(i<size)&&(pos==-1);i++)
    if (((ok_arcs[i][0]==list_full_arcs[arc][c1])&&
              (list_full_arcs[arc][c2]=="?"))||
             ((list_full_arcs[arc][c1]=="?")&&
              (ok_arcs[i][1]==list_full_arcs[arc][c2])))
      pos=i;
  if (pos>-1) {
    here=list_full_arcs[arc][n1];
    there=list_full_arcs[arc][n2];
    list_nodes[there][1] = list_nodes[here][1]+ok_arcs[pos][2];
    list_nodes[there][2] = list_nodes[here][2]+ok_arcs[pos][3];
    list_nodes[there][3] = list_nodes[here][3]+ok_arcs[pos][4];
    list_nodes[there][4] = coords;
    return 1;
  }
  if (list_full_arcs[arc][4]!=INVALID_ARC) {
    list_full_arcs[arc][4]=INVALID_ARC;
    return 1;
  }

  /* no coords found, no invalid arcs found */
  return 0;
}

/*  */
int old2_lib_add_coordinates(int arc,int n1,int n2,int c1,int c2) {
  int size,pos,i,here,there;

  size=sizeof(ok_arcs);
  pos=-1;
  if (list_full_arcs[arc][c1]=="?") {
    for(i=0;(i<size)&&(pos==-1);i++)
      if (ok_arcs[i][1]==list_full_arcs[arc][c2])
        pos=i;
  }
  else if (list_full_arcs[arc][c2]=="?") {
    for(i=0;(i<size)&&(pos==-1);i++)
      if (ok_arcs[i][0]==list_full_arcs[arc][c1])
        pos=i;
  }
  else {
    for(i=0;(i<size)&&(pos==-1);i++)
      if ((ok_arcs[i][0]==list_full_arcs[arc][c1])&&
          (ok_arcs[i][1]==list_full_arcs[arc][c2]))
        pos=i;
  }
  if (pos>-1) {
    here=list_full_arcs[arc][n1];
    there=list_full_arcs[arc][n2];
    list_nodes[there][1] = list_nodes[here][1]+ok_arcs[pos][2];
    list_nodes[there][2] = list_nodes[here][2]+ok_arcs[pos][3];
    list_nodes[there][3] = list_nodes[here][3]+ok_arcs[pos][4];
    list_nodes[there][4] = coords;
    return 1;
  }
  if (list_full_arcs[arc][4]!=INVALID_ARC) {
    list_full_arcs[arc][4]=INVALID_ARC;
    return 1;
  }

  /* no coords found, no invalid arcs found */
  return 0;
}

/*  */
int lib_add_coordinates(int arc,int n1,int n2,int c1,int c2) {
  int size,pos,pos1,pos2,i,here,there,found;

  /* Check if c1 and c2 are index of directional commands */
  size=sizeof(ok_arcs);
  pos1=-1;
  for(i=0;(i<size)&&(pos1==-1);i++)
    if(ok_arcs[i][0]==list_full_arcs[arc][c1])
      pos1=i;
  pos2=-1;
  for(i=0;(i<size)&&(pos2==-1);i++)
    if(ok_arcs[i][1]==list_full_arcs[arc][c2])
      pos2=i;

  /* Try to find the coords */
  switch(pos1) {
    case -1 :
      switch(pos2) {
        case -1 : /* no coords can be found */
          list_full_arcs[arc][4]=SPECIAL_ARC;
          return 1; break;
        default : /* coords can be found */
          pos=pos2; break;
      } break;
    default :
      switch(pos2) {
        case -1 : /* coords can be found */
          pos=pos1; break;
        default : /* inconsistant or coords can be found */
          if(pos1!=pos2) {    /* Its an inconsistant arc */
            list_full_arcs[arc][4]=INVALID_ARC;
            return 1; /* result found */
          }
          pos=pos1; break; /* pos1 or pos2, it doesnt matter */
      } break;
  }

  /* get the coords */
  here=list_full_arcs[arc][n1];
  there=list_full_arcs[arc][n2];
  list_nodes[there][1] = list_nodes[here][1]+ok_arcs[pos][2];
  list_nodes[there][2] = list_nodes[here][2]+ok_arcs[pos][3];
  list_nodes[there][3] = list_nodes[here][3]+ok_arcs[pos][4];
  list_nodes[there][4] = coords;
  return 1;
}

int lib_try_add_coordinates(int i) {
  /* Is it already known inconsistant or not_directional? */
  if ((list_full_arcs[i][4]==INVALID_ARC)||(list_full_arcs[i][4]==SPECIAL_ARC))
    return 0;

  /* arc connects a node with coords and a node without coords */
  /* calculate new coords, set arc type, found something */
  if ((list_nodes[list_full_arcs[i][0]][4]==coords)&&
      (list_nodes[list_full_arcs[i][1]][4]==UNKNOWN_COORDS))
    if (lib_add_coordinates(i,0,1,2,3))
      return 1;
  if ((list_nodes[list_full_arcs[i][0]][4]==UNKNOWN_COORDS)&&
      (list_nodes[list_full_arcs[i][1]][4]==coords))
    if (lib_add_coordinates(i,1,0,3,2))
      return 1;
  return 0;
}

/* arc is 2 nodes, 2 commands and type */
void lib_add_full_arc(int n1,int n2,string c1,string c2,int t) {
  int i,size,pos,turn_arc;

  size=sizeof(list_full_arcs);
  pos=-1;
  for(i=0;(i<size)&&(pos==-1);i++)
    if (((list_full_arcs[i][0]==n1)&&(list_full_arcs[i][1]==n2))||
        ((list_full_arcs[i][0]==n2)&&(list_full_arcs[i][1]==n1)))
      pos=i;
  if(pos>-1)
    return;
  /* add the arc, if possible with c1 is e || sw || s || se */
  switch (c2) {
    case "east"      : turn_arc=1; break;
    case "southwest" : turn_arc=1; break;
    case "south"     : turn_arc=1; break;
    case "southeast" : turn_arc=1; break;
    default          : turn_arc=0; break;
  }
  if (turn_arc)
    list_full_arcs += ({ ({ n2, n1, c2, c1, t }) });
  else
    list_full_arcs +=	({ ({ n1, n2, c1, c2, t }) });
  if(lib_try_add_coordinates(size))
    if(mode==DEBUG_MODE)
      write("coords found after adding full arc "+size+"\n");
  return;
}

/* commands to go from here to there */
/* returns inserted pos or -2 if a full arc was created,  */
/* if "query_pos" is used as command it returns found pos */
int lib_add_half_arc(int here, int there, string command) {
  int i,size,pos;

  size=sizeof(list_arcs);
  /* see if half_arc is already in list --> dont add */
  pos=-1;
  for(i=0;(i<size)&&(pos==-1);i++)
    if ((list_arcs[i][0]==here)&&(list_arcs[i][1]==there))
      pos=i;
  if ((pos>-1)||(command=="query_pos")) {
    write(pos+" half arc already in list\n"); /* TO DO: should not happen */
    return pos;
  }
  /* see if the complement half arc is in list --> add full arc */
  pos=-1;
  for(i=0;(i<size)&&(pos==-1);i++)
    if ((list_arcs[i][1]==here)&&(list_arcs[i][0]==there))
      pos=i;
  if(pos>-1) {
    lib_add_full_arc(here,there,command,list_arcs[pos][2],TWO_WAY_ARC);
    list_arcs=del_array(list_arcs,pos);
    if(mode==DEBUG_MODE)
      write(pos+" removed from half arcs, full arc created\n");
    return -2;
  }
  list_arcs += ({ ({ here, there, command }) });
  if(mode==DEBUG_MODE)
    write(size+" half arcs\n");
  return size;
}

void lib_add_outer_half_arc(string op,string of,string p,string f,string pf) {
  object oroom;
  string *exits;
  int i,size;

  /* TO DO: check if file is there and loads */
/*  move_object(this_player(),op+of);
  oroom=environment(this_player());*/
  oroom=lib_get_room(op+of);
  if(oroom) {
    exits=(string *)oroom->query_room("dest_dir");
    size=sizeof(exits);
    for(i=0;i<size;i+=2) {
      string tmppath;
      tmppath=exits[i];
      if (tmppath[0..0]!="/") tmppath = "/"+tmppath;
/* TO DO: efficiency! */
      if (tmppath==p+f) {
        if(mode==DEBUG_MODE)
          write("Adding halfarc from outer area "+pf+" "+f+" "+exits[i+1]+"\n");
        lib_add_half_arc(lib_add_node(pf),
                       lib_add_node(f),exits[i+1]);
      }
    }
  }
  return;
}

int lib_create_full_arcs() {
  string arc;
  string node1,node2;
  int pos,aa;
  int half_arc_size,count;

  half_arc_size=sizeof(list_arcs);
  if(mode==DEBUG_MODE)
    write("processing arcs started with "+a+"\n");
  for(aa=0;(aa<maxaa)&&(a<half_arc_size);aa++) {
    lib_add_full_arc(list_arcs[a][0],list_arcs[a][1],
                     list_arcs[a][2],"?",ONE_WAY_ARC);
    a++;
  }
  if(a<half_arc_size)
    call_out("lib_create_full_arcs",0); /* sorry the work is not finished */
  else
    call_out("lib_find_coordinates",0); /* sorry the work is not finished */
  return 1;
}

int lib_find_coordinates() {
  int size,i;
  status found_something;

  size=sizeof(list_full_arcs);
  if(mode==DEBUG_MODE)
    write("Looking for coordinates in "+size+" full arcs...\n");
  found_something=1;
  while (found_something) {
    found_something=0;
    for(i=0;i<size;i++) {
      /* arc connects a node with coords and a node without coords */
      /* calculate new coords, set arc type, found something */
      if(lib_try_add_coordinates(i))
        found_something=1;

      /* arc connects two nodes with coords */
      /* check arc consistancy, set arc type, found something */
 
      /* arc connects two nodes without coords */
    }
  }
  call_out("lib_index_nodes",0); /* sorry the work is not finished */
  return 1;
}

status lib_less_node1(int i1, int i2) {
  return (list_nodes[i1][3]>list_nodes[i2][3]);
}

status lib_less_node2(int i1, int i2) {
  return (((list_nodes[i1][3]==list_nodes[i2][3])&&
           (list_nodes[i1][2]>list_nodes[i2][2])) ||
           (list_nodes[i1][3]>list_nodes[i2][3]));
}

status lib_less_node(int i1, int i2) {
  return (((list_nodes[i1][3]==list_nodes[i2][3])&&
          ((list_nodes[i1][2]==list_nodes[i2][2])&&
           (list_nodes[i1][1]>list_nodes[i2][1]))) ||
          ((list_nodes[i1][3]==list_nodes[i2][3])&&
           (list_nodes[i1][2]>list_nodes[i2][2])) ||
           (list_nodes[i1][3]>list_nodes[i2][3]));
}

/* create index array for nodelist, sort on coordinates */
int lib_index_nodes() {
  int i,size;
  int *i_nodes;

  size=sizeof(list_nodes);
  index_nodes=allocate(size);
  for(i=0;i<size;i++)
    index_nodes[i]=i;
/*  if(mode==DEBUG_MODE)
    write("Sorting "+size+" nodes, first pass ...\n");
  i_nodes=sort_array(index_nodes, "lib_less_node1", this_object());
  index_nodes=i_nodes;
  if(mode==DEBUG_MODE)
    write("Sorting "+size+" nodes, second pass...\n");
  i_nodes=sort_array(index_nodes, "lib_less_node2", this_object());
  index_nodes=i_nodes;
*/
  if(mode==DEBUG_MODE)
    write("Sorting "+size+" nodes...\n");
  i_nodes=sort_array(index_nodes, "lib_less_node", this_object());
  index_nodes=i_nodes;
  /* TO DO: check for nodes with same coords */
  call_out("lib_max_coord",0); /* sorry the work is not finished */
  return 1;
}

int lib_max_coord() {
  int i,size;

  size=sizeof(list_nodes);
  if(mode==DEBUG_MODE)
    write("Finding max coordinates in "+size+" nodes...\n");
  if (size==0) {
    write("MAP ERROR: maxing on empty list\n");
    return 0;
  }
  minx=list_nodes[0][1];
  maxx=list_nodes[0][1];
  miny=list_nodes[0][2];
  maxy=list_nodes[0][2];
  minz=list_nodes[0][3];
  maxz=list_nodes[0][3];
  for(i=1;i<size;i++) {
    if (list_nodes[i][1]<minx) minx=list_nodes[i][1];
    else if (list_nodes[i][1]>maxx) maxx=list_nodes[i][1];
    if (list_nodes[i][2]<miny) miny=list_nodes[i][2];
    else if (list_nodes[i][2]>maxy) maxy=list_nodes[i][2];
    if (list_nodes[i][3]<minz) minz=list_nodes[i][3];
    else if (list_nodes[i][3]>maxz) maxz=list_nodes[i][3];
  }
  call_out("lib_create_map",0); /* sorry the work is not finished */
  return 1;
}

/* find a matching arc */
int lib_get_full_arc(int n1,string c1) {
  int i,size,pos,size_ok_arcs;
  string c2;

  size=sizeof(list_full_arcs);
  for(i=0;i<size;i++)
    if ((list_full_arcs[i][0]==n1)&&(list_full_arcs[i][2]==c1))
      return i;
  /* check if the complement direction exists */
  size_ok_arcs=sizeof(ok_arcs);
  pos=-1;
  for(i=0;(i<size_ok_arcs)&&(pos==-1);i++)
    if(ok_arcs[i][0]==c1)
      pos=i;
  if(pos==-1)
    return pos;
  /* check if the complement direction is the way back to here */
  c2=ok_arcs[pos][1];
  for(i=0;i<size;i++)
    if ((list_full_arcs[i][0]==n1)&&(list_full_arcs[i][3]==c2))
      return i;
  return -1;
}

string lib_str1_no_node() {
  if(!node_width)
    return sprintf("%*s",3," ");
  return sprintf("%|*s",node_width,"*");
}

string lib_str_no_node(string arg) {
  string str;
  if(arg)
    str=arg;
  else
    str=" ";
  if(!node_width)
    return sprintf("%*s",3,str);
  return sprintf("%|*s",node_width,str);
}

string lib_str_node(int n_i) {
  string node;
  if(!node_width)
    return sprintf("%|*s",3,(string)n_i);
  node=list_nodes[index_nodes[n_i]][0];
  /* TO DO: if (width>node_witdth) node[node_width..node__width]="#" */
  return sprintf("%|*s",node_width,node);
}

string lib_str_no_arc() {
  int arc_width; /* TO DO: temp, till arc scales ready */
  arc_width=1;
  return sprintf("%*s",arc_width," ");
}

string lib_arc_east(int n_i) {
  string arc;
  int a_i;

  a_i=lib_get_full_arc(index_nodes[n_i],"east");
  if(a_i==-1)
    return " ";
  switch (list_full_arcs[a_i][4]) {
    case TWO_WAY_ARC: arc="-"; break;
    default         : arc="?"; break;
  }
  return arc;
}

string lib_arc_south(int n_i) {
  string arc;
  int a_i;

  a_i=lib_get_full_arc(index_nodes[n_i],"south");
  if(a_i==-1)
    return sprintf("%|*s",node_width," ");
  switch (list_full_arcs[a_i][4]) {
    case TWO_WAY_ARC: arc=sprintf("%|*s",node_width,"|"); break;
    default         : arc=sprintf("%|*s",node_width,"?"); break;
  }
  return arc;
}

string lib_arc_southwest(int n_i) {
  string arc;
  int a_i_next,n_next;

  if(n_i+1==maxn) /* no next node */
    return " ";
  n_next=index_nodes[n_i+1];
  if(((list_nodes[n_next][1]==list_nodes[n][1]+1)&&
      (list_nodes[n_next][2]==list_nodes[n][2]))&&
      (list_nodes[n_next][3]==list_nodes[n][3]))
    a_i_next=lib_get_full_arc(index_nodes[n_i+1],"southwest");
  else
    return " ";
  switch (list_full_arcs[a_i_next][4]) {
    case TWO_WAY_ARC: arc="/"; break;
    default         : arc="?"; break;
  }
  return arc;
}

string lib_arc_southeast(int n_i) {
  string arc;
  int a_i,a_i_next,n,n_next;

  n=index_nodes[n_i];
  a_i=lib_get_full_arc(n,"southeast");
  if(n_i+1!=maxn) {
    n_next=index_nodes[n_i+1];
    if(((list_nodes[n_next][1]==list_nodes[n][1]+1)&&
        (list_nodes[n_next][2]==list_nodes[n][2]))&&
        (list_nodes[n_next][3]==list_nodes[n][3]))
      a_i_next=lib_get_full_arc(index_nodes[n_i+1],"southwest");
    else
      a_i_next=-1;
    if(a_i_next>-1) {
      switch(a_i) {
        case -1 :
          switch (list_full_arcs[a_i_next][4]) {
            case TWO_WAY_ARC: arc="/"; break;
            default         : arc="?"; break;
          }
          return arc; break;
        default :
          switch (list_full_arcs[a_i][4]) { /* TO DO: also look at a_i_next */
            case TWO_WAY_ARC: arc="X"; break;
            default         : arc="?"; break;
          }
          return arc; break;
      }
    }
  }
  if(a_i==-1)
    return " ";
  switch (list_full_arcs[a_i][4]) {
    case TWO_WAY_ARC: arc="\\"; break; /* it will only appear single ;) */
    default         : arc="?"; break;
  }
  return arc;
}

int lib_create_map() {

  maxn=sizeof(index_nodes);
  n=0;
  if (maxn==0) {
    write("MAP ERROR: empty map\n");
    return 0;
  }
  if(mode==DEBUG_MODE)
    write("Creating map from "+maxn+" nodes...\n");
  map="This is what you see in the Mirror of Galadriel:\n";
  if(minz!=maxz)
    map+="\nlevel: "+(string)minz+"\n";
  z=minz-1;
  y=miny-1;
  x=minx-1;
  arcline="";
  call_out("lib_add_to_map",0); /* sorry the work is not finished */
  return 1;
}

lib_add_to_map() {
  int nn,j;

  if(mode==DEBUG_MODE)
    write("Adding to map started from node "+n+" ...\n");
  for(nn=0;nn<maxnn&&(n!=maxn);nn++) {
    if(list_nodes[index_nodes[n]][4]==coords) {
      if(list_nodes[index_nodes[n]][3]!=z) {
        if(z<minz)
          z=minz;
        z=list_nodes[index_nodes[n]][3];
        map+="\nlevel: "+(string)z+"\n";
        y=miny-1;
        x=minx-1;
      }
      if(list_nodes[index_nodes[n]][2]!=y) {
        if(y<miny)
          y=miny;
        map+="\n"+arcline+"\n";
        for(j=y;j<list_nodes[index_nodes[n]][2]-1;j++)
          map+=lib_str_no_node((string)minx+","+(string)y)+"\n\n";
        y=list_nodes[index_nodes[n]][2];
        x=minx-1;
        arcline="";
        /* initial gap on line */
        if(list_nodes[index_nodes[n]][1]!=minx) {
          map+=lib_str_no_node((string)minx+","+(string)y);
          map+=lib_str_no_arc();
          arcline+=lib_str_no_node();
          arcline+=lib_arc_southwest(n);
        }
      }
      if(list_nodes[index_nodes[n]][1]!=x) {
        if(x<minx)
          x=minx;
        for(j=x+1;j<list_nodes[index_nodes[n]][1];j++) {
          map+=lib_str_no_node((string)j+","+(string)y);
          map+=lib_str_no_arc();
          arcline+=lib_str_no_node();
          arcline+=lib_arc_southwest(n); /* TO DO: check for sw arc next node */
        }
        x=list_nodes[index_nodes[n]][1];
      }
      map+=lib_str_node(n);
      map+=lib_arc_east(n);
      arcline+=lib_arc_south(n);
      arcline+=lib_arc_southeast(n);
    }
    n++;
  }
  if(n<maxn)
    call_out("lib_add_to_map",0); /* sorry the work is not finished */
  else {
    map+="\n";
    area_loaded=1;
    call_out("lib_other_jobs",0); /* sorry the work is not finished */
  }
  return 1;
}

int do_dump_no_exits() {
  int i,count;

  count=sizeof(list_no_exits);
  write("\nObjects without obvious exits: "+count+"\n\n");
  for (i=0;i<count;i++)
    write(list_no_exits[i]+"\n");
  return 1;
}

int do_dump_path() {
  int i,count;

  count=sizeof(list_paths);
  write("\nPathnames of connected areas: "+count+"\n\n");
  for (i=0;i<count;i++)
    write(i +"=="+ list_paths[i]+"\n");
  return 1;
}

int do_dump_arc_lengths() {
  int i,count;

  count=sizeof(list_arc_lengths);
  write("\n Found arc lengths: "+count+"\n\n");
  for (i=0;i<count;i++) {
    write(i+" ");
    write(list_arc_lengths[i][0]+" ");
    write(list_arc_lengths[i][1]+" ");
    write(list_arc_lengths[i][2]+"\n");
  }
  return 1;
}

int do_dump_nodes() {
  int i,count;

  count=sizeof(list_nodes);
  write("\n Found nodes: "+count+" x y z type\n\n");
  for (i=0;i<count;i++) {
    write(i+" ");
    write(list_nodes[i][0]+" ");
    write(list_nodes[i][1]+" ");
    write(list_nodes[i][2]+" ");
    write(list_nodes[i][3]+" ");
    write(list_nodes[i][4]+" I: ");
    write(list_nodes[index_nodes[i]][0]+" ");
    write(list_nodes[index_nodes[i]][1]+" ");
    write(list_nodes[index_nodes[i]][2]+" ");
    write(list_nodes[index_nodes[i]][3]+" ");
    write(list_nodes[index_nodes[i]][4]+"\n");
  }
  return 1;
}

int do_dump_arcs() {
  int i,count;

  count=sizeof(list_arcs);
  write("\n Found half arcs: "+count+"\n\n");
  for (i=0;i<count;i++) {
    write("("+list_nodes[list_arcs[i][0]][0]+"^"+
              list_nodes[list_arcs[i][1]][0]+") ");
    write(list_arcs[i][0]+" ");
    write(list_arcs[i][1]+" ");
    write(list_arcs[i][2]+"\n");
  }
  return 1;
}

int do_dump_full_arcs() {
  int i,count;

  count=sizeof(list_full_arcs);
  write("\nFound full arcs: "+count+" there back type\n\n");
  for(i=0;i<count;i++) {
    write("("+list_nodes[list_full_arcs[i][0]][0]+"^"+
          list_nodes[list_full_arcs[i][1]][0]+") ");
    write(list_full_arcs[i][0]+" ");
    write(list_full_arcs[i][1]+" ");
    write(list_full_arcs[i][2]+" ");
    write(list_full_arcs[i][3]+" ");
    write(list_full_arcs[i][4]+"\n");
  }
  return 1;
}

int do_dump_area() {
  do_dump_no_exits();
  do_dump_path();
  do_dump_arc_lengths();
  do_dump_nodes();
  do_dump_arcs();
  do_dump_full_arcs();
  return 1;
}

int do_dump_help() {
  printf(""+
    "ml no_exits  : list objects without obvious exits\n"+
    "ml paths     : list paths of connections to outer areas\n"+
    "ml nodes     : list found nodes in this area\n"+
    "ml half arcs : list found half arcs in this area\n"+
    "ml full arcs : list found full arcs in this area\n"+
    "ml area      : list all of above lists\n"+
    "ml           : try it\n");
  return 1;
}

int do_dump(string arg) {
  if (!area_loaded) {
    write("No area scanned or scanning not complete!\n");
  }
  if (!arg)
    return do_dump_help();
  switch (arg) {
    case "no_exits" : do_dump_no_exits(); break;
    case "paths"    : do_dump_path(); break;
    case "nodes"    : do_dump_nodes(); break;
    case "half arcs": do_dump_arcs(); break;
    case "full arcs": do_dump_full_arcs(); break;
    case "area"     : do_dump_area(); break;
    default         : do_dump_help(); break;
  }
  return 1;
}

int lib_scan_files() {
  object here;
  string herefile;
  string tmppath,tmpfile;
  string *exits;
  string *tmp;
  int size_exits,count,node,i;
  mixed msg2;

  herefile=list_nodes[0][0];
  files=get_dir(list_paths[0]+"*.c");
  /* TO DO: get only _rooms_ ! */
  if(!(maxf=sizeof(files))) {
    write("The Mirror shows you an empty area...\n");
    return 1;
  }
  for(f=0;f<maxf;f++) {
    /* TO DO: check for "^" in the filename ;) */
    herefile=files[f];
    tmp=explode(herefile,".");
    herefile=tmp[0];
    msg2=catch(here=lib_get_room(list_paths[0]+herefile));
    if (msg2)
      write("msg2: "+msg2+"\n");
    if (here) {
      exits=(string *)here->query_room("dest_dir");
      if(!(size_exits=sizeof(exits)))
        list_no_exits += ({ herefile });
      if (size_exits>0) {
        node=lib_add_node(herefile);
        for(i=0;i<size_exits;i+=2) {
          tmp=explode(exits[i],"/");
          tmpfile=tmp[sizeof(tmp)-1];
          tmp=del_array(tmp,sizeof(tmp)-1);
          tmppath=implode(tmp,"/");
          if (tmppath[0..0]!="/") tmppath = "/"+tmppath;
          if (tmppath[-1..-1]!="/") tmppath+="/";
          if (tmppath != list_paths[0]) {
            string ofile;
            ofile=tmpfile;
            tmpfile=(string)lib_add_path(tmppath)+"/"+ofile;
            lib_add_outer_half_arc(tmppath,ofile,list_paths[0],herefile,
                                   (string)lib_add_path(tmppath)+"/"+ofile);
          }
          lib_add_half_arc(node,lib_add_node(tmpfile),exits[i+1]);
        }
      }
    }
  }
  return 1;
}

int lib_get_files() {
  files=get_dir(list_paths[0]+"*.c");
  maxf=sizeof(files);
  if(mode==DEBUG_MODE)
    write("Files to scan: "+maxf+"\n");
  /* TO DO: get only _rooms_ ! */
  if(!(maxf=sizeof(files)))
    write("The Mirror shows you an empty area...\n");
  return 1;
}

int lib_scan_file() {
  object here;
  string herefile;
  string tmppath,tmpfile;
  string *exits;
  string *tmp;
  int size_exits,node,i,ff;
  mixed msg2;

  if(mode==DEBUG_MODE)
    write("\nScanning files started with "+f+"\n\n");
  /* do as much work as possible within the allowed nr of cycles */
  for(ff=0;(ff<maxff)&&(f!=maxf);ff++) {
    /* TO DO: check for "^" in the filename ;) */
    herefile=files[f];
    tmp=explode(herefile,".");
    herefile=tmp[0];
    msg2=catch(here=lib_get_room(list_paths[0]+herefile));
    if (msg2)
      write("msg2: "+msg2+"\n");
    if (here) {
      exits=(string *)here->query_room("dest_dir");
      if(!(size_exits=sizeof(exits)))
        list_no_exits += ({ herefile });
      if (size_exits>0) {
        node=lib_add_node(herefile);
        for(i=0;i<size_exits;i+=2) {
          tmp=explode(exits[i],"/");
          tmpfile=tmp[sizeof(tmp)-1];
          tmp=del_array(tmp,sizeof(tmp)-1);
          tmppath=implode(tmp,"/");
          if (tmppath[0..0]!="/") tmppath = "/"+tmppath;
          if (tmppath[-1..-1]!="/") tmppath+="/";
          if (tmppath != list_paths[0]) {
            string ofile;
            ofile=tmpfile;
            tmpfile=(string)lib_add_path(tmppath)+"/"+tmpfile;
            lib_add_outer_half_arc(tmppath,ofile,list_paths[0],herefile,tmpfile);
          }
          lib_add_half_arc(node,lib_add_node(tmpfile),exits[i+1]);
        }
      }
    }
    f++;
  }
  if(f<maxf)
    call_out("lib_scan_file",0); /* sorry the work is not finished */
  else
    call_out("lib_create_full_arcs",0); /* sorry the work is not finished */
  return 1;
}

int lib_dest_call_out() {
  return remove_call_out("lib_scan_file");
}

int lib_display_map() {
  write(map);
  return 1;
}

int lib_file_map(string arg) {
  if(!arg) {
    write("mf <filename> writes map to file\n");
    return 1;
  }
  if (!area_loaded) {
    write("No area scanned or scanning not complete!\n");
    return 1;
  }
  write_file(arg,map);
  return 1;
}

int do_scan_area() {
  if (!this_player()->query_archwiz()) {
    write("Sorry, but it is an arch-command at the moment...\n");
    return 1;
  }
  lib_init_lists();
  lib_scan_files();
/*  lib_get_files();
  lib_scan_file();*/
  lib_create_full_arcs();
  lib_find_coordinates();
  lib_index_nodes();
  lib_max_coord();
  lib_create_map();
  lib_display_map();
  return 1;
}

int alt_scan_area() {
  if (!this_player()->query_archwiz()) {
    write("Sorry, but it is an arch-command at the moment...\n");
    return 1;
  }
  lib_init_lists();
  lib_read_defines();
  lib_get_files();
  lib_scan_file();
  return 1;
}

int lib_other_jobs() {
/*  lib_find_coordinates();*/
/*  lib_index_nodes();*/
/*  lib_max_coord();*/
/*  lib_create_map();*/
  lib_display_map();
  return 1;
}

int do_scan_help() {
  printf(""+
/*    "ms no_exits  : list objects without obvious exits\n"+
    "ms paths     : list paths of connections to outer areas\n"+
    "ms nodes     : list found nodes in this area\n"+
    "ms half arcs : list found half arcs in this area\n"+
    "ms full arcs : list found full arcs in this area\n"+ */
    "ms area      : scans complete area for consistancy and displays a map\n"+
    "ms           : try it\n");
  return 1;
}

int do_scan(string arg) {
  if (area_loaded) {
    write("Removing previous loaded area "+list_paths[0]+"\n");
    area_loaded=0;
  }
  if (!arg)
    return do_scan_help();
  switch (arg) {
/*    case "no_exits" : do_dump_no_exits(); break;
    case "paths"    : do_dump_path(); break;
    case "nodes"    : do_dump_nodes(); break;
    case "half arcs": do_dump_arcs(); break;
    case "full arcs": do_dump_full_arcs(); break;
    case "area"     : do_scan_area(); break;*/
    case "area"     : alt_scan_area(); break;
    default         : do_scan_help(); break;
  }
  return 1;
}

int tmp_scan_area(string arg) {
  string msg;
  msg=catch(do_scan(arg));
  if (msg)
    write(msg+"\n");
  return 1;
}
