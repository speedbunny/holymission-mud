inherit "obj/weapon";
#define TP this_player()
#define CA capitalize
#define RN this_player()->query_real_name()
#define TO this_object()
#define TPQN TP->query_name()

reset(arg) {
if (arg) return;

    set_name("Staff of Sylvyn");
    set_id("Staff of Sylvyn");
    set_alt_name("staff");
    set_long(
"This is the ancient and powerfull staff of the great Lord Sylvyn. You can\n"+
"sence the pure power of this weapon as it hums softly in your hands. You\n"+
"wonder if you have the power to control such a deadly weapon. It is said\n"+
"that only Immortals may wield the Staff of Sylvyn, for the Staff know's\n"+
"it's own.\n");
    set_type(2);
    set_weight(5);
    set_value(200000);
    modify_stat(1, 460);
    modify_stat(2, 460);
    modify_stat(3, 460);
    modify_stat(4, 460);
    modify_stat(5, 460); 
    modify_stat(6, 460);

    set_hit_func(this_object());
 }
   weapon_hit(attacker) {
write("You hear the mighty hum of this powerful weapon as it starts it's deadly\n"
        +"journey towards the "+attacker->query_name()+"!\n\n");

say("You hear and feel the power of the Staff of Sylvyn as it makes it's deadly\n"
      +"arc towards "+attacker->query_name()+"!\n");
       return 1500000;
}

 wield (arg) {
   if(!TP->query_immortal())  {
write("You may not wield the Staff of Sylvyn, " +CA(TP->query_name())+ " enjoy your\n"+
     "death you foolish mortal!!\n");
     this_player()->hit_player(3000);
     return 1;
}
return ::wield (arg);
}
