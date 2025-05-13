

/* Tegerl, 8.3.1995 */
/* monsters/guard1 */


inherit "obj/monster";
void reset( int arg) 
{
::reset(arg);

if (arg) return;
set_name("guard");
set_alt_name("man");
set_race("human");
set_short("Guard");
set_long("A guard.\n"
       + "This man seems to be very resolut.\n"
       + "Don't do anything that could make him angry.\n");  
set_gender(1);
set_level(25);
add_money(1000);
move_object(clone_object("/players/tegerl/jabberwocky/obj/lance"),
             this_object());
move_object(clone_object("/players/tegerl/jabberwocky/obj/shield"),
             this_object());
command("powerup");
}
void init(){
  ::init();

add_action("north","north");
}
status north(){
if(this_player()->query_level()<30 ){
write("The guard blocks the way and says: " +
      "You are not allowed to enter.\n");
return 1;
}
}
