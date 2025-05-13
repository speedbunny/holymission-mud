
inherit "obj/treasure";
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("tiger");
    set_alias("figurine");
    set_short("A tiger figurine");
    set_long("A small figurine of a tiger, made from solid translucent"+
      " amber. Inlaid onyx forms his stripes, and his eyes glow with the"+
      " radiant blue of sapphires. The beautiful figurine sits on a white"+
      " gold stand. The light dances along his proud blue eyes."+
      " There is a inscription on the bottom of the white gold stand."+
      " It reads: Ian, my love for you will withstand the time we are apart"+
      " and cannot by touched by anything or anyone but you. You enchant"+
      " and charm me, I can only hope in our lifetime together i am able"+
      " to express how much i love and cherish you."+
      "	       I love you very deeply Ian.\n"+
      "    Love,\n"+
      "    Your Lil Hawkress.\n");
    set_weight(0);
    set_value(0);
}

query_auto_load() {
    return "/players/tuppence/secure/tiger:";
}
drop() {
    return 1;
}
pet(str) {
    if (str == "tiger") {
	switch(random(100)) {
	case 0 .. 10 : write("The tiger purrs.\n"); break;
	case 11 .. 20 : write("The tiger licks your hand.\n"); break;
	case 21 .. 30 : write("The tiger pounces your hand.\n"); break;
	case 31 .. 40 : write("The tiger roars at you.\n"); break;
	case 41 .. 50 : write("The tiger growls: I love you!\n"); break;
	case 51 .. 60 : write("The tiger growls: Your a cutie!\n"); break;
	case 61 .. 70 : write("The tiger wiggles his tail.\n"); break;
	case 71 .. 80 : write("The tiger stalks a butterfly.\n"); break;
	case 81 .. 90 : write("The tiger streches and takes a nap.\n"); break;
	case 91 .. 100 : write("The tiger cuddles you.\n"); break;
	}
	return 1;
    }
}

init() {
    ::init();
    add_action("pet","pet");
}
