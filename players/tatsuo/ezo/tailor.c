inherit "/room/room";
#define BS(x)    x
mapping what;
void reset(int flag) {
   if(flag==0) {
      set_light(1);
      short_desc = "In a small chamber, in the ninjas guild";
      long_desc=
	"next to you, you see a small desk where 'Hanzo, a retired black\n"+
	"belted ninja is working with fine fabrics and materials to make\n"+
	"clothing for the guildmembers. There is a small sign fixed\n"+
	"to the northern wall and a door leading to the east.\n";
      what=([  "hachamaka":20  ]);
	items = ({
	  "sign","There is something written on it",
	  "wall","The walls are made out of fine paper mache",
	  "walls","The walls are made out of fine paper mache",
	  "bottom","The bootom is made of brown earth",
	  "ground","The bottom is made of brown earth",
	  "desk","It's an oak wooden desk",
	  "hanzo","He is sitting behind the desk making Hachamakas"
	});
      dest_dir=({  "/players/tatsuo/ezo/weaponery","east",  });
    }
}

void_init() {
    add_action("do_read","read");
    add_action("do_buy","buy");
    ::init();
}

int do_read(string arg) {
    string *arr;
    int i, sz;
    if (arg!="sign") return 0; 
    arr = m_indices(what);
    write("Buyable items currently:\n\n");
    for (sz = sizeof(arr),i = 0; i < sz; i ++)
	printf("%-10s for %-8s coins\n",arr[i],to_string(what[arr[i]]));
        write("\n");
    write(BS("The Hachamaka autoload and protect the head a bit. "+
	"The colour of the hachamaka shows you the guild status "+
	"of of the ninja. In a row the colours are: white, yellow, orange, "+
	"blue, green, brown, black, red, and white."));
    return 1;
}

int do_buy(string arg) {
   if(member(what,arg)!=1) {
	notify_fail(BS("Hanzo tells you: "+
	    "Sorry, but I don't sell "+arg+"."));
	return 0;
    }
   else if(this_player()->query_money()<what[arg]) {
	notify_fail(BS("Hanzo tells you: "+
	    "Sorry, but you can't afford the "+arg+"."));
	return 0;
    } 
   else if(present(arg,this_player())) {
	notify_fail(BS("Hanzo tells you: "+
	    "Sorry, but I sell only one "+arg+" to one member."));
	return 0;
    }
   switch(arg) {
    case "hachamaka":
        move_object(clone_object("/players/tatsuo/guild/narmour/bandana"),
	  this_player());
	break;
    }
    write(BS("Hanzo gives you the "+arg+"."));
    this_player()->add_money(-what[arg]);
    return 1;
}
