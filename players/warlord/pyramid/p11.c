inherit"room/room";
object o1;
reset(arg) {
if(!o1){o1=clone_object("players/warlord/pyramid/tombg");
transfer(o1,this_object());
}
if (arg) return;
set_light(1);
short_desc="Stairwell \n";
long_desc="This is a stone stairwell. You see a bright light from the top\n";
dest_dir=({
"players/warlord/pyramid/p3","downnortheast",
"players/warlord/pyramid/p14","upsouthwest",
});
}
