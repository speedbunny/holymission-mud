inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("raptor");
set_short("Rapter");
set_long("This is a small but very mean looking dinousour. It stands\n"+
         "on two legs and has very big teeth. The claws on its feet\n"+
         "look like they could rip a man in half!\n");
set_level(13);
set_ac(5);
set_wc(18);
set_aggressive(1);
}
