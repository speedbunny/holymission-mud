/******************************************************************************/
/* Wand of Wizards - Created by Uranus                                        */
/******************************************************************************/
 
inherit "obj/armour";
 
#define VERSION "1.31"
#define DATE    "28 Aug 1991"
#define OBJEKT  "tools/wand/wand"
 
#define HELPOBJ    "tools/wand/wandhelp"
#define SPECIALOBJ "tools/wand/wandextra"
#define PRESAYOBJ  "tools/wand/presay"
#define OBJECTOBJ  "tools/wand/objmaker"
#define MONSTEROBJ "tools/wand/monmaker"
#define ROOMOBJ    "tools/wand/roommaker"
#define NORMALOBJ "obj/normal_write"
 
/* #define DEBUG 1 /**/
#define NEUTR 10
 
int    lighted;
status is_wielded,is_worn,is_quitting,to_wield,to_wear,to_light,dbg;
object is_marked,temp,normal;
string presay,extralook,owner;
int    refr;
 
/******************************************************************************/
 
query_name() {
  return "wand";
}
 
query_info() {
  return "Uranus' Wand --- Version " + VERSION + " (" + DATE + ")";
}
 
query_auto_load() {
  int i;
  string ps,el;
  i = 0; ps = ""; el = "";
  if (is_wielded) i = i + 1;
  if (is_worn)    i = i + 2;
  if (dbg)        i = i + 4;
  if (!environment()->query_wizard()) i = 0;
  if (presay)    ps = "#" + presay;
  if (extralook) el = "#$" + extralook;
  if (extralook && !presay) ps = "#*";
  if (ps=="#")              ps = "#*";
  if (environment()->query_level() < 10) return 0;
  return OBJEKT + ":" + i + "#" + lighted + ps + el;
}
 
query_value() {
  int val;
  val = 1000;
  if (is_wielded)  val = val +  800;
  if (is_worn)     val = val + 1200;
  if (lighted > 0) val = val +  500;
  if (lighted < 0) val = val -  900;
  return val;
}
 
query_weight() {
  return 1;
}
 
weapon_class() {
  int lvl;
  if (!is_wielded) return 0;
  lvl = environment()->query_level();
  if (lvl < 5)  return 5;
  if (lvl < 10) return 8;
  if (lvl < 15) return 11;
  if (lvl < 20) return 14;
  if (environment()->query_wizard()) return 24;
}
 
hit(attacker) {
  if (!environment()->query_wizard()) return 0;
  if (call_other(attacker,"query_alignment",0) > NEUTR * 4 && lighted >= 0) {
    write("You miss the good creature because your shining wand likes the good creatures.\n");
    return "miss";
  }
  if (call_other(attacker,"query_alignment",0) < NEUTR * -4 && lighted <= 0) {
    write("You miss the evil creature because your dark wand protects their creatures.\n");
    return "miss";
  }
  write("BANG!!! You smash the poor creature extremly hard.\n");
  return 100000;
}
 
/******************************************************************************/
 
id(str) {
  return str == "wand" || str == "wand of wizards";
}
 
short() {
  string wield,wear,light,name;
  if (owner) name = capitalize(owner) + "'s";
  else name = "The";
  if (is_wielded)       wield = " (wielded)";   else wield = "";
  if (is_worn)          wear  = " (worn)";      else wear  = "";
  if (lighted > 0)      light = " (glowing)";
  else if (lighted < 0) light = " (very dark)"; else light = "";
  return name + " wand of wizards" + light + wear + wield;
}
 
long() {
  if (lighted > 0) write("It is a bright glowing long and worn wand.\n");
  if (lighted ==0) write("It is a long and worn wand.\n");
  if (lighted < 0) write("It is a dark black long and worn wand.\n");
  write("This wand is very powerful, so don't forget it somewhere else.\n");
  write("Even a powerful wizard probaly can't use it in all details.\n");
  write("Try 'help wand' for help, perhaps this wand has more power than\n");
  write("you even can imagine now.\n");
  return 1;
}
 
extra_look() {
  string text;
  text = capitalize(environment()->query_pronoun());
  if (!environment()->query_wizard())
    return text + " wants to become a follower of the alchemist Kazdek";
  if (!extralook)
    return text + " is a follower of the master alchemist Kazdek";
  if (extralook == "*") return 0;
  else return extralook;
}
 
/******************************************************************************/
 
query_presay() {
  if (presay=="") return 0;
  if (presay) return presay + " ";
  return 0;
}
 
query_normal() {
  if (normal) return normal;
  return 0;
}
 
query_creator(obj) {
  return do_test_object("presay",PRESAYOBJ)->q_creator(obj);
}
 
ladjust(str, n) {
  return extract(str+"                                                ",0,n-1);
}
 
radjust(str, n) {
  string tmp;
  tmp = extract("                                                     "+str,0);
  return extract(tmp,strlen(tmp)-n);
}
 
do_getalignment(align) {
  return do_test_object("presay",PRESAYOBJ)->q_alignment(align);
}
 
do_armour() {
  int lvl,wiz;
  if (dbg) write("WAND - DEBUG: do_armour()\n");
  if (!is_worn) {
    call_other(this_object(),"set_ac",0);
    return;
  }
  call_other(this_object(),"set_id","wand");
  call_other(this_object(),"set_type","cloak");
  lvl = environment()->query_level();
  wiz = environment()->query_wizard();
  if (lvl < 10) { call_other(this_object(),"set_ac",1); return 1; }
  if (lvl < 20) { call_other(this_object(),"set_ac",2); return 1; }
  if (!wiz) { this_object()->set_ac(2); return 1; }
  call_other(this_object(),"set_ac",99); return 1;
}
 
do_test_object(str,cln) {
  object obj;
  obj = first_inventory(this_object());
  while(obj) {
    if (obj->id(str)) return obj;
    obj = next_inventory(obj);
  }
  obj = clone_object("/"+cln); move_object(obj,this_object());
  return obj;
}
 
query_marker(num) {
  return is_marked[num];
}
 
parse_list(str) {
  return do_test_object("presay",PRESAYOBJ)->parse_list(str);
}
 
init_speech() {
/* DONT |
  add_action("do_presay",     "wsay");
  add_action("speak_say",     "say");
  add_action("speak_tell",    "tell");
  add_action("speak_shout",   "shout");
  add_action("speak_wizshout","wshout");
*/
}
 
free_owner() {
  int i;
  command("drop wand",environment(this_object()));
  owner=0;
  presay=0;
  extralook=0;
  dbg=0;
  for (i=0; i<10; i++) is_marked[i]=0;
  is_quitting=0;
  return 1;
}
 
/******************************************************************************/
 
handle_quit() {
  is_quitting=1;
  return 0;
}
 
drop() {
  if (is_quitting) return 1;
  if (is_wielded) do_unwield("wand");
  if (is_worn)    do_unwear("wand");
  return 0;
}
 
get()  { return 1; }
 
un_wield() {
  is_wielded = 0; return 1;
}
 
reset(arg) {
  string a,b;
  if (!arg) {
    if (sscanf(file_name(this_object()),"%s#%s",a,b)==2){
	  write("The Wand of Wizards....\n");
	  if (!normal) {
		normal = clone_object(NORMALOBJ);
		move_object(normal,this_object());
	  }
	}
    set_light(-lighted); lighted=0; is_wielded=0; is_worn=0;
    presay=0; extralook=0; dbg=0; do_armour();
    refr=0; is_quitting=0;
    is_marked = allocate(10);
#ifdef DEBUG
    dbg=1;
#endif
  }
  if (dbg) write("WAND - DEBUG: reset(" + arg + ")\n");
  return 1;
}
 
init_arg(str) {
  int flag,light;
  if (sscanf(str,"%d#%d#%s#$%s",flag,light,presay,extralook) != 4) {
    extralook = 0; if (sscanf(str,"%d#%d#%s",flag,light,presay) != 3) {
      presay = 0; if (sscanf(str,"%d#%d",flag,light) != 2) {
        light = 0; sscanf(str,"%d",flag);
      }
    }
  }
  if (presay == "*") presay = "";
  to_wield=(flag&1); to_wear=(flag&2); dbg=(flag&4);
  to_light=light;
  if (dbg) write("WAND - DEBUG: init_arg(" + str + ")\n");
  return 1;
}
 
init() {
  string str;
  if (dbg) write("WAND - DEBUG: init()\n");
  if (!owner && environment(this_object())==this_player()) {
#ifdef DEBUG
    str = ctime(time()) + " " + ladjust(this_player()->query_real_name(),16);
    str = str + " (light " + to_light;
    if (to_wear)  str = str + ", worn";
    if (to_wield) str = str + ", wielded";
    if (presay)   str = str + ", presay";
    str = str + ")\n";
    log_file("uranus.wand",str);
#endif
    owner = this_player()->query_real_name();
  }
  if (environment(this_object())!=this_player() ||
      (owner && owner!=this_player()->query_real_name())) return 1;
  do_armour();
  if (!refr)    { call_out("refresh",30); refr=1; }
  if (to_wield) { do_wield("wand");       to_wield = 0; }
  if (to_wear)  { do_wear("wand");        to_wear = 0; }
  if (to_light) { set_light(to_light);    lighted = to_light; to_light = 0; }
  add_action("do_wield","wield");	add_action("do_unwield","unwield");
  add_action("do_wear","wear");		add_action("do_unwear","remove");
  add_action("do_remove","wandkill");	add_action("do_wandhelp","help");
  add_action("handle_quit","quit");
  if (this_player()->query_level() > 14) {
    init_speech();
  }
  if (this_player()->query_level() > 19) {
    add_action("do_light","wlight");	add_action("do_silence","wsilence");
    add_action("do_go","wgoto");	add_action("do_cry","wcrash");
    add_action("do_echo","$");		add_action("do_shout","#");
    add_action("do_fetch","wfetch");	add_action("do_mark","wmark");
    add_action("do_lookplayer","wlp");	add_action("do_lookplayer","wlookplayer");
    add_action("do_objects","wob");	add_action("do_objects","wobjects");
    add_action("do_patch","wpatch");	add_action("do_destr","wdestr");
    add_action("do_trace","wtrace");	add_action("do_destrroom","wdestrroom");
    add_action("do_wave","wcreate");	add_action("do_destrnum","wdestrnum");
    add_action("do_long","wlong");	add_action("do_info","winfo");
    add_action("do_align","walign");	add_action("do_who","wwho");
    add_action("do_mail","wmail");	add_action("do_roomlook","wlook");
    add_action("do_review","wreview");	add_action("do_roomexits","wexits");
    add_action("do_quests","wquest");	add_action("do_reset","wreset");
    add_action("do_forceload","wload");	add_action("do_exam","wexam");
    add_action("do_castle","wcastle");	add_action("do_extra","wextra");
    add_action("do_showbits","wbits");	add_action("do_ip","waddr");
    add_action("do_transfer","wtrans"); add_action("do_frog","wfrog");
    add_action("do_tell","wtell");	add_action("do_report","wreport");
    add_action("do_force","wforce");    add_action("do_snoops","wsnoops");
    add_action("do_debug","debug");     add_action("debugger","",1);
  }
  return 1;
}
 
/******************************************************************************/
 
do_remove() {
  object obj,obj2;
  write("You destroy the Wand of Wizards, nobody knows why...\n");
  set_light(-lighted); lighted=0;
  if (is_worn) do_unwear("wand");
  if (is_wielded) {
    if (dbg) write("WAND - DEBUG: stop_wielding()\n");
    call_other(this_player(),"stop_wielding"); is_wielded = 0;
  }
  obj = first_inventory(this_object());
  while(obj) { obj2 = obj; obj = next_inventory(obj); destruct(obj2); }
  destruct(this_object());
  return 1;
}
 
/******************************************************************************/
 
do_wandhelp(str) {
  object ob;

  if (!this_player()->query_wizard()) return; /* Fuck non wizards ... Herp */

  if (str == "wand" && this_player()->query_level() < 15) {
    write("Wand of Wizards - Commands:\n\n");
    write("help wand    - This HELP for not yet wizards\n");
    write("wandkill     - Destroy the Wand\n\n");
    write("Perhaps the Wand is even for unexperienced players wieldable or wearable?\n");
    return 1;
  }
  if (str == "wand" && !this_player()->query_wizard()) {
    write("Wand of Wizards - Commands:\n\n");
    write("help wand    - This HELP for not yet wizards\n");
    write("wandkill     - Destroy the Wand\n");
    write("wsay <title> - Gives you a title when saying,shouting\n\n");
    write("Perhaps the Wand is even for unexperienced players wieldable or wearable?\n");
    return 1;
  }
  if (!this_player()->query_wizard()) return 0;
  if (str == "wand") {
    write("Wand of Wizards - Commands:\n\n");
    write("help wand          - This HELP for wizards\n");
    write("help misc          - Miscellaneous Wand commands\n");
    write("help obj           - Object manipulation commands\n");
    write("help room          - Room examination commands\n");
    write("help player        - Player and Monster examination commands\n");
    write("help item          - Help about item description used by the Wand\n");
    write("wear/remove wand   - The Wand cloaks you with AC 99\n");
    write("wield/unwield wand - The Wand has a WC of 100000 for bad creatures\n");
    write("wandkill           - Destroy the Wand\n");
    return 1;
  }
  if (str == "misc" || str == "obj" || str == "room" || str == "player" ||
      str == "item") {
    ob = do_test_object("wandhelp",HELPOBJ);
    return call_other(ob,"cmd_help",str);
  }
  return 0;
}
 
/******************************************************************************/
 
do_wield(str) {
  if (dbg) write("WAND - DEBUG: do_wield(" + str + ")\n");
  if (!id(str)) return 0;
  if (environment() != this_player()) {
    write("You must get the Wand of Wizards first! But how?\n");
    return 1;
  }
  if (is_wielded) {
    write("You already wield the Wand of Wizards!\n");
    return 1;
  }
  is_wielded = 1;
  call_other(this_player(), "wield", this_object());
  return 1;
}
 
/******************************************************************************/
 
do_unwield(str) {
  if (dbg) write("WAND - DEBUG: do_unwield(" + str + ")\n");
  if (!id(str)) return 0;
  if (!is_wielded) return 0;
  call_other(this_player(),"stop_wielding");
  is_wielded = 0;
  write("OK.\n");
  return 1;
}
 
/******************************************************************************/
 
do_wear(str) {
  object ob;
  if (dbg) write("WAND - DEBUG: do_wear(" + str + ")\n");
  if (!id(str)) return 0;
  if (environment() != this_player()) {
    write("You must get the Wand of Wizards first! But how?\n");
    return 1;
  }
  if (is_worn) {
    write("You are already cloaked by the Wand of Wizards!\n");
    return 1;
  }
  is_worn = 1;
  do_armour();
  ::wear(str);
  if (!call_other(this_object(),"query_worn")) {
    is_worn = 0;
    do_armour();
  }
  return 1;
}
 
/******************************************************************************/
 
do_unwear(str) {
  if (dbg) write("WAND - DEBUG: do_unwear(" + str + ")\n");
  if (!id(str)) return 0;
  if (!is_worn) return 0;
  ::remove(str);
  is_worn = 0;
  do_armour();
  return 1;
}
 
/******************************************************************************/
 
do_light(str) {
  if (!str) {
    write("Total light level: " + set_light(0) + "\n");
    return 1;
  }
  if (str == "on") {
    lighted += 1; set_light(1);
    write("Wand's light level: " + lighted + ".\n");
    return 1;
  }
  if (str == "off") {
    lighted -= 1; set_light(-1);
    write("Wand's light level: " + lighted + ".\n");
    return 1;
  }
  write("Usage: WLIGHT to show light level of room,\n");
  write("       WLIGHT ON to increase light level of wand and\n");
  write("       WLIGHT OFF to decrease light level of wand.\n");
  return 1;
}
 
/******************************************************************************/
 
do_mark(str) {
  int i;
  object ob;
  string text;
  if (!str) {
    write("Usage: WMARK <num> <object> to mark that object for further use.\n");
    write("       WMARK <num> * to remove marker,\n");
    write("       WMARK ? to show actual marker settings.\n");
    return 1;
  }
  if (str == "?") {
    write("Object marker settings are:\n");
    for (i=0 ; i<10 ; i++) {
      write("Marker \%" + i + ": ");
      if (is_marked[i]) write(is_marked[i]);
      else write("empty");
      write("\n");
    }
    return 1;
  }
  if (sscanf(str,"%d %s",i,text)!=2) return 0;
  if (i<0 || i>9) return 0;
  if (text == "*") {
    is_marked[i] = 0;
    write("Object marker \%" + i + " removed.\n");
    return 1;
  }
  ob = parse_list(text);
  if (!ob) {
    write("No object called '" + text + "' found.\n");
    return 1;
  }
  is_marked[i] = ob;
  write("Ok.\n");
  return 1;
}
 
/******************************************************************************/
 
wave_get_file(str) {
  if (!str || str == "%") { write("[Aborted]\n"); return 1; }
  call_other(temp,"make",lower_case(str));
  return 1;
}
 
do_wave(str) {
  if (str == "object" || str == "monster" || str == "room") {
    if (str=="object")  temp = do_test_object(str,OBJECTOBJ);
    if (str=="monster") temp = do_test_object(str,MONSTEROBJ);
    if (str=="room")    temp = do_test_object(str,ROOMOBJ);
    write("Give the name of the file: ");
    input_to("wave_get_file"); return 1;
  }
  write("Usage: WCREATE OBJECT  to edit an object description file.\n");
  write("       WCREATE MONSTER to edit a monster description file.\n");
  write("       WCREATE ROOM    to edit a room description file.\n");
  return 1;
}
 
/******************************************************************************/
 
do_extra(str) {
  if (!str) {
    write("Usage: WEXTRA <title> to set the extra_look() title,\n");
    write("       WEXTRA * to set the wand to no title,\n");
    write("       WEXTRA % to set the wand to the default title,\n");
    write("       WEXTRA ? to display the actual title.\n");
    return 1;
  }
  if (str == "?") {
    if (extralook!="*") write(extra_look()+"\n");
    else write("NO title is set.\n");
    return 1;
  }
  if (str == "*") {
    extralook = "*";
    write("Title removed.\n");
    return 1;
  }
  if (str == "%") {
    extralook = 0;
    write("Title reset.\n");
    return 1;
  }
  extralook = str;
  write("OK.\n");
  return 1;
}
 
/******************************************************************************/
 
do_presay(str) {
  string plr;
  if (!str) {
    write("Usage: WSAY <title> to set title for SAY etc.\n");
    write("       WSAY * to remove a title,\n");
    write("       WSAY ? to display the title.\n");
    return 1;
  }
  if (str == "?") {
    plr = capitalize(this_player()->query_real_name());
    if (presay) write("Title is: '" + presay + " " + plr + " says:'\n");
    else write("No title set, you're just '" + plr + " says:'\n");
    return 1;
  }
  if (str == "*") {
    presay = 0;
    write("Title removed.\n");
    return 1;
  }
  presay = str;
  write("OK.\n");
  return 1;
}
 
/******************************************************************************/
 
refresh() {
  object ob,qt,obj;
  status qtyper,deb;
  int cnt,flag;
  obj = environment(this_object());
  if (!living(obj) || !owner) return 0;
  if (owner != obj->query_real_name()) return 0;
  qtyper = 0; cnt = 1; flag = 0;
  ob = first_inventory(obj);
  while (ob) {
    if (cnt<3 && ob->id("wand of wizards")) flag = cnt;
    if (ob->id("quicktyper")) { qt = ob; qtyper = 1; }
    if (ob->id("speeder")) { qt = ob; qtyper = 1; }
    ob = next_inventory(ob); cnt = cnt + 1;
  }
  if (flag - qtyper != 1) {
    if (dbg) { tell_object(obj,"WAND - DEBUG: refresh()\n"); }
    deb = dbg; dbg = 0;
    if (qtyper) move_object(qt,this_object());
    move_object(this_object(),environment(obj));
    move_object(this_object(),obj);
    if (qtyper) move_object(qt,obj);
    dbg = deb;
  }
  call_out("refresh",30);
  return 1;
}
 
/******************************************************************************/
 
debugger(str) {
  if (!dbg) return 0;
  if (str) write("WAND - DEBUG: '" + query_verb() + "' '" + str + "'\n");
  else     write("WAND - DEBUG: '" + query_verb() + "' ''\n");
  return 0;
}
 
/******************************************************************************/
 
do_debug(str) {
  if (!id(str)) return 0;
  dbg = dbg + 1; if (dbg>1) dbg = 0;
  if (dbg) write("Enabled debugging...\n");
  else write("Disabled debugging...\n");
  return 1;
}
 
/******************************************************************************/
 
speak_test() {
  if (!query_presay() && query_verb()!="wshout") return 0;
  return do_test_object("presay",PRESAYOBJ);
}
 
speak_say(str) { object obj;
  obj=speak_test(); if (!obj) return 0; call_other(obj,"d_say",str); return 1; }
 
speak_tell(str) { object obj;
  obj=speak_test(); if (!obj) return 0; call_other(obj,"d_tell",str); return 1; }
 
speak_shout(str) { object obj;
  obj=speak_test(); if (!obj) return 0; call_other(obj,"d_shout",str); return 1; }
 
speak_wizshout(str) { object obj;
  obj=speak_test(); if (!obj) return 0; call_other(obj,"d_wizshout",str); return 1; }
 
/******************************************************************************/
 
do_lookplayer(str) { return do_test_object("wandspecial",SPECIALOBJ)->cmd_lookplayer(str); }
do_objects(str)    { return do_test_object("wandspecial",SPECIALOBJ)->cmd_objects(str); }
do_long(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_long(str); }
do_info(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_info(str); }
do_exam(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_exam(str); }
do_showbits(str)   { return do_test_object("wandspecial",SPECIALOBJ)->cmd_showbits(str); }
do_silence(str)    { return do_test_object("wandspecial",SPECIALOBJ)->cmd_silence(str); }
do_go(str)         { return do_test_object("wandspecial",SPECIALOBJ)->cmd_go(str); }
do_patch(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_patch(str); }
do_destr(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_destr(str); }
do_destrroom(str)  { return do_test_object("wandspecial",SPECIALOBJ)->cmd_destrroom(str); }
do_destrnum(str)   { return do_test_object("wandspecial",SPECIALOBJ)->cmd_destrnum(str); }
do_trace(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_trace(str); }
do_who(str)        { return do_test_object("wandspecial",SPECIALOBJ)->cmd_who(str); }
do_mail(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_mail(str); }
do_ip(str)         { return do_test_object("wandspecial",SPECIALOBJ)->cmd_ip(str); }
do_roomlook(str)   { return do_test_object("wandspecial",SPECIALOBJ)->cmd_roomlook(str); }
do_roomexits(str)  { return do_test_object("wandspecial",SPECIALOBJ)->cmd_roomexits(str); }
do_review(str)     { return do_test_object("wandspecial",SPECIALOBJ)->cmd_review(str); }
do_quests(str)     { return do_test_object("wandspecial",SPECIALOBJ)->cmd_quests(str); }
do_reset(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_reset(str); }
do_castle(str)     { return do_test_object("wandspecial",SPECIALOBJ)->cmd_castle(str); }
do_transfer(str)   { return do_test_object("wandspecial",SPECIALOBJ)->cmd_transfer(str); }
do_force(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_force(str); }
do_tell(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_tell(str); }
do_report(str)     { return do_test_object("wandspecial",SPECIALOBJ)->cmd_report(str); }
do_align(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_align(str); }
do_forceload(str)  { return do_test_object("wandspecial",SPECIALOBJ)->cmd_forceload(str); }
do_cry(str)        { return do_test_object("wandspecial",SPECIALOBJ)->cmd_cry(str); }
do_echo(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_echo(str); }
do_shout(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_shout(str); }
do_crash(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_crash(str); }
do_fetch(str)      { return do_test_object("wandspecial",SPECIALOBJ)->cmd_fetch(str); }
do_frog(str)       { return do_test_object("wandspecial",SPECIALOBJ)->cmd_frog(str); }
do_snoops(str)     { return do_test_object("wandspecial",SPECIALOBJ)->cmd_snoops(str); }
 
/******************************************************************************/
