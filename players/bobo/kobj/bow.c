/*
 *  a long-bow (uses Padrones 'automatic weapon' (thanx))
 *
 */

inherit "players/kelly/obj/autowpn";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("longbow");
    set_alias("bow");
    set_class(7);              /* When used as a club */
    set_weight(2);
    set_value(500);
    set_short("A longbow");
    set_long("This is a very longbow how it is used by centaurs.\n"+
         "It is made of a fine wood. There are also some arrows.\n"); 
    set_max_bullets(20);
    set_reload_msg("notches some arrows to");
    set_empty_msg("There are no arrows left.");
    set_open_msg("You pull back the string of the bow and aim for");
    set_open_rmsg("pulls back the string and aims for");
    set_bullet_name("arrow");
    set_bullets(20);
    set_max_salvo(2);
    set_wc_per_bullet(10);
    set_sound("Zack");
    set_value_per_bullet(10);
    set_monster_reload(1);
    }
} /* reset */
