inherit "/obj/weapon";

#include <defs.h>
#include <material.h>
#include <objects.h>
#include <damage.h>

private static int wisdom_needed;

int weapon_hit(object attacker);
nomask private static void orc_held();
nomask private static void half_orc_held();
int wield(object weap);
nomask int query_wisdom_needed();
int get();

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("kistik");
  set_alias_list(({ "Kistik", "orc bane", "sword", "shortsword" }));
  set_weight(2);
  set_value(5000);
  set_class(16);
  set_magic(3);
  set_size(2);
  set_material(MITHRIL);
  set_type(SLASH);
  set_hit_func(this_object());
  set_wield_func(this_object());
  set_short("Kistik, Orc Bane");
  set_long("Kistik, Orc Bane, is a vibrant shortsword crafted to "+
    "ward against orcs, although some might say it was made to "+
    "exterminate them. Only those with strong wills can overcome "+
    "this weapon. It has runes engraved upon its blade.\n");
  set_info("Kistik was fashioned a century ago by a great kobold "+
    "enchanter by the name of Thuk-bar. It was created to protect "+
    "the kobolds from the orcs living in the mountains. Although "+
    "Thuk-bar was most likely the last of the great kobold "+
    "enchanters, his works are still around. Kistik was his last "+
    "creation, and it is said that the spirit of the greatest "+
    "kobold guard of the time is instilled within the blade.\n");
  set_read("The runes entail pictures of a large kobold, nearly "+
    "the size of a gnome, holding off half a dozen orcs in a "+
    "mountainous pass. There are no words that go with the scene.\n);
  wisdom_needed = 15 + random(20);
}

int weapon_hit(object attacker) {
  switch(attacker->query_real_race()) {
    case "orc" :
      if(wielded_by->query_player())
        writelw("Kistik slices through the soul of the orc, tearing "+
                "part of its lifeforce from it in a bluish glow.\n");
      say(lw(CAP(wielded_by->NAME) + " cuts " +
          lower_case(attacker->NAME) + " with " + wielded_by->POS +
          " shortsword leaving a bleeding gash and a flash of blue!\n"));
      attacker->hit_by_other(10+random(21), ({ DEATH_MAGIC }),
                             ({ 1 }), ({ -3 }));
      return 10;
    case "half-orc" :
      if(wielded_by->query_player())
        writelw("Kistik slices through the soul of the half-orc, "+
                "tearing the orcish part of its lifeforce from it "+
                "in a bluish glow.\n");
      say(lw(CAP(wielded_by->NAME) + " cuts " +
          lower_case(attacker->NAME) + " with " + wielded_by->POS +
          " shortsword leaving a bleeding gash and a flash of blue!\n"));
      attacker->hit_by_other(5+random(11), ({ DEATH_MAGIC }),
                             ({ 1 }), ({ -3 }));
      return 5;
    case "goblin" :
      return 5;
    case "hobgoblin" :
      return 5;
    default : break;
  }
  return 0;
}

nomask private static void orc_held() {
  if(TP->query_player())
    writelw("Kistik slices through the your orcish soul! It "+
            "feels as though a burning sharp blade is cutting "+
            "you from the inside! You drop the sword from the "+
            "intense pain!\n");
  TP->hit_by_other(10+random(21), ({ DEATH_MAGIC }),
                   ({ 1 }), ({ -3 }));
}

nomask private static void half_orc_held() {
  if(TP->query_player())
    writelw("Kistik slices through the orcish part of your soul! "+
            "It feels as though a burning sharp blade is cutting "+
            "you from the inside! You drop the sword from the "+
            "intense pain!\n");
  TP->hit_by_other(10+random(21), ({ DEATH_MAGIC }),
                   ({ 1 }), ({ -3 }));
}

int wield(object weap) {
  int    i, sz;
  string *dirs;
  object start;

  switch(TP->query_real_race()) {
    case "orc" :
      orc_held();
      return 0;
    case "half-orc" :
      half_orc_held();
      return 0;
    case "goblin" : return 0;
    case "hobgoblin" : return 0;
    default :
      if(wisdom_needed > TP->query_wis() && !TP->id("Urk-barr")) {
        writelw("Kistik finds you to be an incompetent, weak-minded "+
                "fool, and sends you on your way!\n");
        start = ENV(TP);
        for(i=0; i<5 && TP->query_property("NO_FEAR")<40; i++) {
          if(ENV(TP) && dirs = ENV(TP)->query_dest_dirs()) {
            if(sz=(sizeof(dirs)/2)) {
              last_cmd = dirs[(random(sz)*2)+1];
              command(last_cmd, TP);
            }
          }
        }
        MOVE(TO, start);
        return 0;
      }
  }
  return 1;
}

nomask int query_wisdom_needed() {
  return wisdom_needed();
}

int get() {
  switch(TP->query_real_race()) {
    case "orc" :
      orc_held();
      return 0;
    case "half-orc" :
      half_orc_held();
      return 0;
    case "goblin" : return 0;
    case "hobgoblin" : return 0;
  }
  return 1;
}
