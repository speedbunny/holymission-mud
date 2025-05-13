inherit "/obj/monster";
 reset(int arg)
 {
 ::reset(arg);

 load_chat(40,({"BZZZZzzzzz\n"}));

 load_a_chat(62,({"BZZZ BZZZ\n"}));

if (arg) return;
set_name("killer wasp");
set_alias("wasp");
set_race("animal");
set_short("Huge killer wasp");
set_long("Oh. You have never seen such huge wasp. \n"
          +" Run AWAY !!! It looks very angry.\n");
set_wc(14);
set_ac(1);
set_aggressive(1);
set_al(-120);
set_level(19);
set_size(3);
move_object(clone_object("/players/goldsun/sherwood/obj/huge_sting"),
             this_object());
}
