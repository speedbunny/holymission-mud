inherit "room/room";
reset (arg){
if (arg) return ;
set_light(1);
short_desc = "Kitty and Meecham's talking room";
long_desc = "      You have just entered the room Baalthasar in his \n"
+"kindess has designated the talking room for the talkative Lady \n"
+"Kitty and her consort Lord Meecham.\n\n";
dest_dir = ({"/players/baalthasar/workroom.c", "baal"});
}
