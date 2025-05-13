inherit "/obj/weapon";

reset(arg)
{
   ::reset(arg);
   if (arg) return;

   set_name("ninja-to");
   set_short("Ninja-to of Hellish Poison");
   set_long("This is the legendary Ninja-to of Hellish Posion. The blade\n"+
            "was forged from the shadows of the night, giving the blade\n"+
            "its flat black color. Only the most skilled ninjas' dare to\n"+
            "wield this weapon. You shutter to think what might happen if\n"+
            "this blade was to be wielded by a non-ninja.\n");
   set_alias("to");
   set_info("nin");
   set_class(22);
   set_value(3400);
   set_weight(3);
   set_hit_func(this_object());

}
query_auto_load(){
return "players/akira/weapons/ninja:";
}
drop() {
destruct(this_object());
write("Your ninja-to returns to the shadows.\n");
return 1;
}

init()
{
     ::init();
     add_action("no_wield", "wield");
}

no_wield(str) {
        if(this_player()->query_guild() !=8 || 
           this_player()->query_level() < 27) {
write("THE BLADE STRIKES AT YOU!\n");
this_player()->hit_player(this_player()->query_hp()-1);
        return 1;
        }
        }

weapon_hit(attacker){
if(random(20) <=5)
write("Your foe's body is filled with poison from your blade!\n");
tell_object(attacker, "Your blood boils from the hellish poisons in your blood!\n");
attacker->add_poison(25);
return;
}


