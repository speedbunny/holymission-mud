inherit "room/room";

object chief,guard;

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="The chief's hut";
    long_desc="You are in the hut of the Fauns' chief.\n"+
              "An assortment of item, including a shield, some weapons,\n" +
              "and trophies decorate the walls.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/faun_mark2","west",
             });
    items = ({
              "shield","Sparkles and shines but is too thin to be useful",
              "weapons","primitive spears and rock knives",
              "trophies","Mounted heads of great deer, boar, and wolf",
            });
    if(!objectp(chief)) {
    chief=clone_object("players/kelly/monster/chief");
    move_object(chief,this_object());
    }
    if(objectp(guard)) {
    guard=clone_object("players/kelly/monster/guard");
    move_object(guard,this_object());
    }
}
