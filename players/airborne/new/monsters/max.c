inherit "obj/monsters";
object glass, robe;
string chat_str;
string a_chat_str;

reset(arg){
::reset(arg);  
  if(arg) return;
   
  if(!chat_str){
 	chat_str = allocate(10);
        a_chat_str = allocate(5);

 chat_str[0] = "Max says: The unicorn has been stolen!\n";
 chat_str[1] = "Max says: Trogs are a peaceful folk, why do they bother us?\n";
 chat_str[2] = "Max says: The unicorn has been our friend for so long.\n";
 chat_str[3] = "Max says: The duegar must pay!\n";
 chat_str[4] = "Max fixes his glasses.\n";
 chat_str[5] = "Max says: I would save him myself if I knew where he was...\n";
 chat_str[6] = "Max says: If I weren't so old, I would find him myself.\n";
 chat_str[7] = "Max scratches his nose.\n";
 chat_str[8] = "Max ponders the existance of life.\n";
a_chat_str[0] = "Max gives you an evil glare.\n";
a_chat_str[1] = "Max dances about you with the grace of a brick.\n";
a_chat_str[2] = "Max says: Stop that!\n";
a_chat_str[3] = "Max shouts: Make them stop beating me!\n";
a_chat_str[4] = "Max says: You are without a doubt, an asshole!\n";

		}
 set_name("max");
 set_race("trog");
 set_gender(1);
 set_size(3);
 set_alt_name("old trog");
 set_level(20);
 set_ac(7);
 set_wc(14);
 set_hp(400);
 add_money(1000);
 set_aggressive(0);
 set_short("An old trog");
 set_long
("A tall slender Trog that look exceptionally old. He is wearling a great\n"+
 "colorful robe and a pair of glasses.\n");
 load_chat(100, chat_str);
 load_a_chat(20, a_chat_str);
     robe = clone_object("obj/armour");
     robe-> set_type("armour");
     robe-> set_name("robe");
     robe-> set_short("A multi-colored robe");
     robe-> set_long("A bright multi-colored robe.\n");
     robe-> set_size(3);
     robe-> set_ac(1);
     robe-> set_weight(1);
     robe-> set_value(100);
	move_object(robe, this_object());
 glass = clone_object("obj/armour");
 glass-> set_type("glasses");
 glass-> set_name("glasses");
 glass-> set_ac(0);
 glass-> set_value(100);
 glass-> set_weight(1);
 glass-> set_short("A pair of glasses");
 glass-> set_long("A pair of glasses.\n");
	move_object(glass, this_object());

	init_command("powerup");

	return 1;
	}


