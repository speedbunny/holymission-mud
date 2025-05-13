inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("scarlet macaw");
   set_alias("macaw");
   set_level(6);
   set_wc(8);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("bird");
   set_short("Scarlet Macaw");
   set_long("This bird is nearly three feet in size and is bright red.  It\n"+
            "has powerful wings as well as a storong beak.  It is a very\n"+
            "vocal bird calling to other macaws in racous, hoars tones.\n");
}
