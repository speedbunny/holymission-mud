inherit "obj/monster";

string chat_str;
string a_chat_str;

reset(arg){
::reset(arg);  
  if(arg) return;
   
  if(!chat_str){
 	chat_str = allocate(5);
        a_chat_str = allocate(5);

 chat_str[0] = "Barney says: They destroyed my tavern! \n";
 chat_str[1] = "Barney curses the duegar.\n";
 chat_str[2] = "Barney screams: They should all die!\n";
 chat_str[3] = "Barney says: The duegar must pay!\n";
 chat_str[4] = "Barney looks like he's about to cry.\n";
a_chat_str[0] = "Barney says: You're as bad as them!\n";
a_chat_str[1] = "Barney says: Might as well kill me, I have nothing to live for.\n";
a_chat_str[2] = "Barney says: Stop that!\n";
a_chat_str[3] = "Barney shouts: Make them stop beating me!\n";
a_chat_str[4] = "Barney says: You are without a doubt, an asshole!\n";

		}
 set_name("barney");
 set_race("trog");
 set_gender(1);
 set_size(3);
 set_alt_name("sad trog");
 set_alias("trog");
 set_level(13);
 set_ac(5);
 set_wc(10);
 set_hp(400);
 add_money(100);
 set_aggressive(0);
 set_short("A sad trog");
 set_long("Barney is the former bar tender at the tavern. He looks upset.\n");
 load_chat(50, chat_str);
 load_a_chat(20, a_chat_str);
   
	}
