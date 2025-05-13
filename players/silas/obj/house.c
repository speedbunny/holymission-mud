/*   PLAYER OWNED HOUSE */

/* change this to the path of this code */
#define path "players/silas/obj/house"
/*place exited to*/
#define dest "/room/vill_road2"
#define abort "-q"
#define sentinel "**"
#define cost 1

string owner,desc,short_desc,temp,temp2;
int rentdue;

reset() {return 1;}

id(str) {return str == "house";}

init() {
    if(time()>rentdue) {
        clear_owner();
        }
    if (owner && (this_player()->query_real_name() != owner) &&
        this_player()->query_level() < 20) {
        write("This house is owned by someone else.\n");
        move_player(this_player(),dest); 
        }
    else {
        write("Welcome!\n");
        add_action("own_house","rent");
        add_action("set_descrip","describe house");
        }
    return 1;
    }

long() {
    if(owner) {
        write(desc);
        return 1;
        }
    else
        write("This is an unowned house.\n");
        write("You may rent this house for a week by typing RENT.\n");
        write("The cost is "+cost+" coins per week");
        write("Noone else may enter your house except wizards.\n");
        write("There are no furnishings right now, but the room comes\n");
        write("with it's own description command.");
        write("Houses will not keep through a crash or shutdown.\n");
        return 1;
        }

short() { return short_desc;}   

set_descrip() {
    if(!(this_player()->query_name()==owner)) {
        write("You do not own this house.\n");
        return 1;
        }
    temp=" ";
    temp2=" ";
    write("Type in the description here.\n");
    write("Type "+sentinel+" to stop.\n");
    write("Type "+abort+" to abort.\n");
    input_to("getline");
    return 1;
    }

getline(str) {
    if(str=abort) {return 1;}
    if(str=sentinel) {
        desc=temp;
        return 1;
        }                             
    temp2=temp+str;
    temp=temp2;
    input_to("getline");
    return 1;
    }

own_house() {
/* THIS SHOULD NEVER HAPPEN  */
    if(owner&&!(owner==this_player()->query_real_name())) {
      write("This house is already owned by someone else.\n");
      return 1;
      }
    if(this_player()->query_money()<=cost) {
        write("You haven't enough money to rent this house.");
        return 1;
        }
    set_owner(this_player()->query_real_name());
    this_player()-add_money(-cost);
    write("You now own this house.\n");
    write("You can now describe the room with the DESCRIBE HOUSE command\n");
    write("You can avoid having your stuff destroyed one week from now\n");
    write("by renting the house again before the expiration date one week\n");
    write("from now.\n");
    return 1;
    }


set_owner(o) {
    owner = o;
    desc = o+"'s house";
    short_desc = desc;
    rentdue=time()+604800;
    }

clear_owner() {
    owner="";
    short_desc="Unowned House";
    }
