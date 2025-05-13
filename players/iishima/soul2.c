#define SPLS "/players/meecham/guild/spells/"
#define AS SPLS + "attack/"

mapping times;
static mapping spells;
static mapping misc;
int guild;

status try_spell(string args, string file);

status id(string str) { return str == "druidsoul" || str == "guildsoul"; } 

status drop() { return 1; }

void reset(status arg) {
  int tm;
  if(arg) return;
  guild = "guild/master"->query_number("druid");
  tm = time();
  times = 
    ([ "cause light"    :   1; tm + 1,   "cause serious" :   1; tm + 1,
       "cause critical" :   2; tm + 2,   "cure light"    :   1; tm + 1,
       "cure serious"   :   2; tm + 2,   "cure critical" :   3; tm + 3,
       "harm"           :   3; tm + 3,   "heal minor"    :   3; tm + 3,
       "heal major"     :   3; tm + 3,   "barkskin"      :   1; tm + 1,
       "call lightning" :   2; tm + 2,   "create"        :   1; tm + 1,
       "entangle"       :   2; tm + 2,   "fireshield"    :   1; tm + 1,
       "firestorm"      :   4; tm + 4,   "flameblade"    :   1; tm + 1,
       "heat armour"    :   5; tm + 5,   "light"         :   1; tm + 1,   
       "harness wind"   :  30; tm + 30,  "earthquake"    :   2; tm + 2,
       "remove poison"  :   2; tm + 2,   "slay living"   :   5; tm + 5 ]);
  spells =
    ([ "cause", "cure", "harm", "heal", "barkskin", "call", "create",
       "entangle", "fireshield", "firestorm", "flameblade", "heat", 
       "light", "remove", "slay", "harness", "earthquake" ]);
  misc = ([ "druid", "dr", "dhelp" ]);
}       

void init() {
  add_action("_cast","cast");
  add_action("druid_hook","",1);
/*
  max_essence = 100 + (30 * (LVL(TP) + LLVL(TP));
*/
  set_heart_beat(1);
}

status _cast(string str) {
  string *sname, args, file;  
  int i,j;

  if (!str) {
    write("Cast what?\n");
    return (1);
  }

  sname = explode(str, " ");
  
  if (!member(spells, sname[0]))  
    return (0);
  
  i = sizeof(sname);
  if (i > 1) 
    for (j = 1;j < i;j++)
      if (j == 1) args = sname[j];
      else args += " " + sname[j];
  file = (AS + "_" + sname[0] + ".c");
  if (file_size(file) == -1)
    file = (SPLS + "_" + sname[0] + ".c");
  return (try_spell(args, file));
}

status druid_hook(string str) {
  string verb, file;
  
  verb = query_verb();
  if(verb == "druid/") verb = "dr";
  
  if (!member(misc, verb))  
    return (0);
   
  file = (SPLS + "_" + verb + ".c");
  return (file->do_spell(str));
}

status try_spell(string args, string file) {
  file->do_spell_checks(args, this_object(), file);
  return (1);
}

string short() {
  if (this_player()->query_immortal()) 
    return ("Druid soul");
  return (0);
}

void long() {
  printf("This is your druid guild soul.\n");
}

void check_allow_spell(string spell, string file)
{
  if(time() > times[spell,1]) {
    times[spell,1] = time() + times[spell,0];
    call_out("allow_it",0,file);
    return;
  }
  printf("You can't cast %s again so soon.\n", spell);
}

status allow_it(string file) {
  file->do_spell();  
}

status get() { return (1); }

void guild_changes() {
  if (this_player()->bark_shadow()) this_player()->dest_me();
  if (this_player()->fireshield()) this_player()->dest_me();
  if (present("flameblade", this_player()))
    destruct(present("flameblade", this_player()));
  return;
}

/* 01.03.97 - Airborne: Exact numbers for HP and SP are 
   not allowed. Neither are percentages. Use the standard 
   descriptions that everyone else has. This removal will 
   also save some heart_beats that are used needlessly.
  
void heart_beat() {
  object mon;
  int sp,max_sp,hp,max_hp,mon_hp,mon_max_hp,mon_pct;

  sp = environment(this_object())->query_sp();
  max_sp = environment(this_object())->query_max_sp();
  hp = environment(this_object())->query_hp();
  max_hp = environment(this_object())->query_max_hp();
  if (environment(this_object())->query_attack()) {
    mon = environment(this_object())->query_attack();
    mon_hp = mon->query_hp();
    mon_max_hp = mon->query_max_hp();
     mon_pct = mon_hp * 100 / mon_max_hp;
    tell_object(environment(this_object()), "HP: " + hp +
      " (" + max_hp + ")     SP: " + sp + " (" + max_sp +
      ")     " + mon->query_name() + ": " + mon_pct + "%\n");

      ")\n");
}
*/
