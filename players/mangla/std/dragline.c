inherit "obj/std_trans";

reset(int arg) {

    if(arg) return;
/* shows as the object in the room name. */
    set_short("Flying dragon");
/* used to "look at" the transport. */
    set_alias("dragon");
/* What player on outside sees when looking at the transport. */
    set_long("A very large dragon looms up before you. There " +
             "appears to be several saddles resting atop the " +
             "top of the dragon. You can feel that this is a " +
             "tame beast and you have nothing to fear.\n");
/* what the player sees as the desc of the object from the inside. if the
object is at a stop then the player also sees the outside desc. of
the room. *.
    set_inside_long("Nice long desc here.\n");
/* Message seen by those inside the transport when a player exits. */
    set_inside_enter("climbs aboard and takes a place on a saddle.\n");
/* Message seen by the outside players when the player enters the
transport. */
    set_outside_enter("climbs up onto the dragon and takes a seat.\n");
/* what the people int he same room and the object see when player
exits the transport. appended by player name. Message not seen
if player is invisible. */
    set_outside_leave("drops from the top of the dragon.\n");
/* The message seen by the players on the inside of the object when
a player leaves. */
    set_inside_leave("climbs down looking for adventure.\n");
/* Set this as a flying vehicle.
also availible set_water(int) */
    set_flying(1);
/* The time the object spends at a stop. */
    stop_time(60);
/* The time the object spends in transit. */
    trans_time(30);
/*  Set the number of rooms an dhte destinations of each room.
the second arg is an array with the room that CLONES
this object being the last room. */
    set_rooms(3,({"players/mangla/rooms/prison",
                  "players/mangla/rooms/test",
                  "players/mangla/workroom"}));
    ::reset(arg);
}
