/* Ear version 1.0 By Xanathar - The Beholder     */
/* A player tracking device. It captures all talk */

#define minlevel 20

inherit "/obj/monster";

object commander;
string tracking;
int    busy;
int    all;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("ear");
    set_alias("spy");
    set_short("A floating Ear");
    set_long("The Ear is hovering in the air, carefully listening to you.\n");
    set_race("unknown");
    set_gender(0);
    set_level(7);
    set_hp(128);
    set_al(-250);
    set_ep(4152);
    set_wc(2);
    set_ac(5);
    set_aggressive(0);
    load_chat(2,({"The Ear floats to a better spot to hear you.\n"}));
  }
}

init() {
 ::init();
 add_action("spy_on","spy");
 add_action("force_ear","force");
 add_action("set_mode","mode");
 add_action("plug_ear","plug");
 add_action("kill_ear","kill");
 add_action("info_ear","info");
 add_action("zap_ear","zap");
 add_action("zap_ear","destruct");
 }

zap_ear(arg) {

  if ((arg != "ear") && (arg !="spy")) return 0;
  if (call_other(this_player(),"query_level") < minlevel) {
      write("What do you think you are ? A wizard ?.\n");
      return 1;
      }
     write("Now. That was NOT very nice of you.\n");
     if (commander) tell_object(commander,"(Some tried to ZAP/DESTRUCT ear !)\n");
     return 1;
 }


info_ear(arg) {

  if (call_other(this_player(),"query_level") < minlevel) {
      write("The Ear pretends it is deaf.\n");
      return 1;
      }

  write("Ear Version 1.0 By Xanathar - The Beholder.\n"+
        "This is a player tracking device. It overhears any conversation\n"+
        "in the room the tracked players is in. It follows automatically.\n");
  write("Options : Spy <player> , Mode <all/words> All gives non-talks also.\n");
  return 1;
  }

plug_ear(arg) {
  if (arg=="ear") {
     write("The ear quickly increases its altitude, so you can't reach it.\n");
     return 1;
     }
  return 0;
  }

kill_ear(arg) {
  if (arg=="ear") {
     write("The ear avoids your blow with ease.\n");
     return 1;
     }
  return 0;
  }

mode_port(arg) {
  all=arg;
  }

set_mode(arg) {

  if (call_other(this_player(),"query_level") < minlevel) {
      write("The Ear pretends it is deaf.\n");
      return 1;
      }

  if (arg=="all") {
     all=1;
     write("Mode : All\n");
     } else {
     all=0;
     write("Mode : spoken words only.\n");
     }
  return 1;
  }


catch_tell(str) {

 int ok;
 string a,b;
 object me;

 if (busy==1) return 1;
 me = this_object();
 busy=1;
 ok=0;

 if ((commander) && (me)) {
    if (str) {
       sscanf(str,"%s leaves %s.\n",a,b);
       if ((a==tracking) && (b)) {
          command(b,me);
          ok=1;
          }
       a=0;b=0;
       sscanf(str,"%s says: %s\n",a,b);
       if ((a) && (!ok)) {
          tell_object(commander,"("+a+" says: "+b+")\n");
          ok=1;
          }
       if ((!ok) && (all)) {
          sscanf(str,"%s\n",a);
          tell_object(commander,"("+a+")\n");
          }
     }
 }
 busy=0;
}

force_ear(str) {
  if (call_other(this_player(),"query_level") < minlevel) {
      write("The Ear pretends it is deaf.\n");
      return 1;
      }
 command(str);
 return 1;
 }

spy_on(str) {
   object who;
   object here;

   if (call_other(this_player(),"query_level") < minlevel) {
      write("The Ear behaves as if you said something rather stupid.\n");
      return 1;
      }

   commander = this_player();
   who       = find_living(str);

   if (who) {
      write("The ear nods solemly, and disappears.\n");
      say("The ear nods solemly, and disappears.\n",this_player());
      here=environment(who);
      move_object(this_object(),here);
      tell_object(who,"A floating ear appears from nowhere. It is listening.\n");
      tracking=capitalize(str);
      return 1;
      } else {
      write("The ear fades away for a brief moment, but then returns.\n"+
            "It didn't hear you quite right.\n");
      return 1;
      }
   }

spy_port(arg) {
  object who;
  object here;
  who = find_living(arg);
  if (who) {
     here=environment(who);
     say("The ear suddenly disappears without a trace.\n");
     move_object(this_object(),here);
     tell_object(who,"A floating ear appears from nowhere. It is listening.\n");
     tracking=capitalize(arg);
     return 1;
     }
  return 0;
  }

msg_port(arg) {
 say(arg+".\n");
 return 1;
 }

set_commander(arg) {
    commander=arg;
    }


