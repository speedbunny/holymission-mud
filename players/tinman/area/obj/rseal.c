inherit "/obj/treasure";
void reset ( int tick ) {
    ::reset ( tick);
    if ( tick ) return;
    set_name("ruler seal");
    set_alias("seal");
    set_short("Ruler Seal of the Han Dynasty");
    set_long("This is the Ruler Seal of Ancient Han Dynasty. It's a jade stamp made to a cube bottom and a scuplture of the Imperial Dragon holding a burning pearl. It pronounces it's "+
      "owner the ruler of China.\n");
    set_weight(1);
    set_value(5000);
}
