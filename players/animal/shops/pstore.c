pay(str) {
    object pet;
    int coins, stuff;
	if(!str) return 0;
 
    if (sscanf(str,"%d",coins) == 1) {
        if (coins < 1000 || coins > 19000) {
            write("That price of pet cannot be made, sorry.\n");
            return 1;
        }
        if (this_player()->query_money() < coins) {
            write("Come back when you have enouch money!\n");
            return 1;
        }
	stuff = coins / 1000;
        pet = clone_object("players/animal/shops/pet");
        pet->patch_owner(this_player()->query_real_name());
        pet->set_level(stuff);
	pet->set_ep(stuff*10);
        pet->set_ac(stuff/2);
        if(stuff <= 4) pet->set_ac(2);
        pet->set_wc(stuff);
        pet->set_hp(11*stuff);
        move_object(pet, this_object());
	write("Your pet has arrived!!\n");
        say(this_player()->query_name()+"'s pet has arrived!\n");
        this_player()->add_money(-coins);
	write_file("/players/animal/shops/pets",this_player()->query_real_name()+
	": "+coins+" on "+ctime(time())+"\n");
        return 1;
    }
}
 
get_it(str) {
     if(str != "instructions") return 0;
     write("You get the instructions for pet usage.\n");
     move_object(clone_object("players/animal/shops/instruct"),
                 this_player());
     return 1;
}
 
init() {
    add_action("north","north");
    add_action("pay","pay");
    add_action("get_it","get");
}
 
long() {
    write("Animal's Amazing Pets\n\n"+
          "\tThis is Animal's pet store, like everything else\n"+
          "\tin Animal's world, this is a unique pet store!\n"+
          "\tA small note on the counter reads:\n\n"+
          "\t\tAnimal's Pets are wild, you can tell us\n"+
          "\t\thow much ya wanna spend, and we will make\n"+
          "\t\tthe pet from scratch using a special magical\n"+
          "\t\tpotion, its easy, and you spend what you want!\n"+
	"\t\tOf course, the more ya spend, the better your pet!\n\n"+
          "\tSyntax:  'pay <amount>' where <amount> is how\n"+
          "\tmuch you wanna spend on yer pet.\n"+
          "\tA small instruction book is available so you have\n"+
          "\tno trouble using your pet, type 'get instructions'.\n\n");
    write("The only obvious exit is north.\n");
}
 
north() {
    this_player()->move_player("north#players/animal/shops/shop_street4");
    return 1;
}
 
reset(arg) {
    if (arg) return;
    set_light(1);
}
 
short() {
    return "Animal's Amazing Pets"; 
}

