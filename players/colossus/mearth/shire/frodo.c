inherit "obj/monster";
object sting;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("frodo");
    set_short("Frodo the hobbit");
    set_long(
      "This is Frodo. He doesn't realize you've entered his room as he's deep\n"+
      "in thought as he tries to finish his poem. Though Frodo may be small\n"+
      "he's a very sturdy hobbit and can suprise most people with his courage\n"+
      "and skill.\n");
    load_chat(20, ({
	"Frodo says: Leave me in peace, I wish to work on my poetry.\n",
	"Frodo looks out of his window deep in thought.\n",
	"Frodo says: When will Bilbo get home?\n",
      }));
    load_a_chat(25, ({
	"Frodo fights back like a caged animal, slashing at you.\n",
	"Frodo calls to Legolas and Gimli for help.\n",
      }));
    set_race("hobbit");
    set_level(15);
    set_size(2);
    set_gender(1);
    set_al(200);
    add_money(random(500)+1000);
    set_ac(7);
    sting=clone_object("/players/colossus/mearth/shire/sting");
    move_object(sting, this_object());
    command("wield sting", this_object());
}
