inherit "obj/monster";
string chat_str;
string a_chat_str;

reset(arg){
::reset(arg);  
  if(arg) return;
   
  if(!chat_str){
 	chat_str = allocate(10);
        a_chat_str = allocate(5);

 chat_str[0] = "Milly says: He is so forgetable.\n";
 chat_str[1] = "Milly says: How does he expect anyone to find the horn when he has it?\n";
 chat_str[2] = "Milly says: He spends to much time resting lately.\n";
 chat_str[3] = "Milly says: The duedar turned the unicorn to stone!\n";
 chat_str[4] = "Milly scratches herself.\n";
 chat_str[5] = "Milly says: I think Max is colorblind.\n";
 chat_str[6] = "Milly says: If he didn't spend so much time in that stupid tent...\n";
 chat_str[7] = "Milly sobs.\n";
 chat_str[8] = "Milly says: Even Prong the warrior cannot save the unicorn without the horn.\n";
a_chat_str[0] = "Milly says: STOP!\n";
a_chat_str[1] = "Milly dances about you with the grace of a brick.\n";
a_chat_str[2] = "Milly says: Go fight the duegar, not me!\n";
a_chat_str[3] = "Milly shouts: Help! Max, help!\n";
a_chat_str[4] = "Milly says: You are without a doubt, an asshole!\n";

		}
 set_name("milly");
 set_race("trog");
 set_gender(2);
 set_size(3);
 set_alt_name("old maid");
 set_level(10);
 set_ac(3);
 set_wc(10);
 set_hp(400);
 add_money(10);
 set_aggressive(0);
 set_short("An old maid");
 set_long("Milly is a rather old trog who cares for Max's estate.\n");
 load_chat(50, chat_str);
 load_a_chat(20, a_chat_str);

	}
