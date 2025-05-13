inherit "obj/npc";

int clones;

reset (arg) 
{
  object ob;
 ::reset(arg);
  if (!arg) {
    set_name("grazzt");
    set_alt_name("tana-ri");
    set_level(150);
    set_al(-1000);
    set_aggressive(1);
    set_wc(100);
    set_hp(15000);
    set_race("greater demon");
    set_size(4);
    set_short("Grazzt");
    set_long("The lord Grazzt looks like a very large human with black\n"+
             "skin, pointed ears and long sharp teeth. As you enter he \n"+
             "grins and attacks....\n");
    if(sizeof(explode(file_name(this_object()),"#"))>1)
        "players/jewel/quest/swords/sword2"->xxx();
move_object(clone_object("players/jewel/quest/hills/crystal"),this_object());
move_object(clone_object("players/jewel/quest/hills/mbracers"),this_object());
move_object(clone_object("players/llort/secure/archrobe"),this_object());
move_object(clone_object("players/llort/secure/girdle"),this_object());
    ob = clone_object("/obj/shadows/fireshield_shad");
    apply(call,ob,"start_shadow",this_object(),0,1);
    set_attacks(3);
    set_attacks_change(100);
    set_dead_ob(this_object());
    experience=20000000;
    add_money(100000 + random(100000));
  }
  clones=0;
}

detect_invis() { return 1; }

hold(o,t) { write("Grazzt is much to powerful for this punny attack.\n"); }

int monster_died(object mon)
{

   if(!this_player()->query_immortal())
   {
       shout(
"With an enormous explosion half of the 23rd abyssal layer crumbles to dust\n"+
"as "+ this_player()->query_name()+" strikes the final blow at Grazzt,\n"+
"Ruler of outer planes and Overlord of the Tana-Ri warforce!!!\n");
   }
   return 0;
}

heart_beat()
{ 
    ::heart_beat();
    if(query_hp()<10000 && clones<1 && !present("marilith",environment()))
    {
        clones=1;
        say("\nGrazzt utters the words 'pgnw'\n");
        clone_object("players/jewel/quest/hills/marilith")->move_player(
          "BANZAI",environment(),1,"steps out of a flickering gate");
    }

    if(query_hp()<3000 && clones<2 && !present("balor",environment()))
    {
        clones++;
        say("\nGrazzt utters the words 'pgnw'\n");
        clone_object("players/jewel/quest/hills/balor")->move_player(
          "BANZAI",environment(),1,"steps out of a flickering gate");
    }
}

query_guild() { return 3; }
