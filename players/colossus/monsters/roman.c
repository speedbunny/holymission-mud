inherit"obj/monster";
string chats;
object gladius, cuirbolli;

get_chats() {
    if (!chats){
	chats = allocate(3);
	chats[0]="The Roman Legionaire watches you intently, looking for trouble.\n";
	chats[1]="The Roman Legionaire fingers his gladius as he eyes you.\n";
	chats[2]="The Roman Legionaire says: Claudius is immortal.\n";
    }
    return chats;
}
reset(arg){
    ::reset(arg);
    if (arg) return;
    set_gender(1);
    set_race("human");
    set_level(10);
    set_al(5);
    set_ac(10);
    set_wc(12);
load_chat(10,get_chats());
set_name("roman");
set_alt_name("legionaire");
    set_short("A Roman Legionaire");
    set_long("A Roman Legionaire who is more than ready if you cause trouble.\n");
gladius=clone_object("/players/colossus/weapons/gladius");
cuirbolli=clone_object("/players/colossus/armors/cuirbolli");
move_object(gladius, this_object());
move_object(cuirbolli, this_object());
init_command("wield gladius");
command("wear cuirbolli");
}
