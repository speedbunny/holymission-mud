inherit"obj/monster";

object horn;

reset(arg){
  ::reset(arg);
  if(!arg){
 set_name("unicorn");
 set_short("Unicorn");
 set_long("This is the famed Unicorn of Avalon, believd by many to be the\n"+
          "last of its kind. Though beautiful to behold, you can't help but\n"+
          "how deadly the horn of the unicorn could be.\n");
 set_level(75);
 set_aggressive(0);
 set_wc(30);
 set_ac(75);
 horn=clone_object("players/ambrose/avalon/weapons/horn");
 move_object(horn,this_object());
 init_command("wield horn");
 set_dead_ob(this_object());
 }
}
monster_died(ob){
 write("You have slain the last Unicorn.  Truly you are the most evil\n"+
       "person in the world.\n");
 return 0;
}
