/* Changed by Ethereal Cashimor, to remove a bug. 220493, The hat
   should NOT have armourtype 'armour' but 'hat' */
/* Uglymouth 940113, Put hat and staff in separate files and defined
      functions in them so mages can use the stuff too. */

inherit "obj/monster";
object staff,hat;

reset(arg) {
  ::reset(arg);
  if(!arg) {

    set_name("sorceror");
    set_alias("lord");
    set_short("Sorceror Lord");
    set_long("This is the Almighty Sorceror Lord. He reigns over all in this area.\n");
    set_level(60);
    set_wc(60);
    set_al(300);
    set_spell_dam(100);
  }

  if(!present("sorceror's hat",this_object())) {
    staff = clone_object("/players/warlord/weapons/sorcstaff");
    transfer(staff,this_object());
/* Uglymouth: Old sorceror didn't wield it, tho it was intended
   to do so. n_ac is much better and used before, therefore commented.
    command("wield staff");
*/
  }
  if(!present("sorceror's hat",this_object())) {
    hat = clone_object("/players/warlord/armours/sorchat");
    transfer(hat,this_object());
    command("wear hat");
  }
}
