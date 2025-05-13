inherit "obj/monster";

reset(arg) {
  ::reset(arg);

  if(!arg) {
    set_name("orc general");
    set_alt_name("orc");
    set_alias("orc");
    set_short("The orc general");
    set_long("This the orc general, in command of this legion of orcs.\n");
    set_race("orc");
    set_gender(1);
    load_a_chat(10,({"Orc general says: Ha! you kill me? never!!\n",
                     "Orc general says: Idiot!\n",
                     "Orc general says: I'm almost as strong as Shagratt.\n",
                     "Orc general says: Prepare for your last defeat!\n",
                     "Orc general says: Another victory!",
                     "Orc general shouts: Tell Shagratt i'll take of care of these intruders.\n",
                     "Orc general sings: 'victory victory'.\n",}));
    set_level(30);
    set_hp(2000);
    set_al(-500);
    set_ep(15000);
    set_wc(20);
    set_ac(6);
    set_aggressive(1);
    add_money(2000+random(5000));
    set_whimpy(-1);
    transfer(clone_object("/players/shaka/weapons/olsword")
    ,this_object());
    transfer(clone_object("/players/shaka/armour/oshield")
    ,this_object());
    transfer(clone_object("/players/shaka/armour/ochain")
    ,this_object());
    transfer(clone_object("/players/shaka/obj/dkey")
    ,this_object());
    init_command("wield sword");
    init_command("wear shield");
    init_command("wear chainmail");
  }
}


attack()
{
object victim;
string naampie;
int iets;

  if (::attack())
   {
     victim=this_object()->query_attack();
     naampie = victim->query_name();
     iets=random(100);
     if (iets<60) return 1;
     if ( (iets>=60) && (iets<75) )
      {
       victim->hit_player(random(30));
       say("Orc general swings his sword and creates a gaping wound!\n");
       write("Orc general creates a gaping wound in "+naampie+"'s body.\n");
       return 1;
      }
     if ( (iets>=75) && (iets<90) )
      {
       victim->hit_player(random(30));
       say("Orc general hits you with a smashing uppercut!\n");
       write("Orc general hit "+naampie+" with a smashing uppercut!\n");
       return 1;
      }
     if ( (iets>=90) && (iets<=100) )
      {
       victim->hit_player(random(40));
       say("Orc general knocked you of your feet!\n");
       write("Orc general knocked "+naampie+ " of his feet.\n");
       return 1;
      }
     return 1;
   }
  return 0;
}
