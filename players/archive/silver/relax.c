/* Rejected from the new mage guild but I will leave it in here for future info */
/*                                           Saffrin  */


/* -----------------------------------------------------------------------
This is a code made by Whisky but has been altered to meet the 
class of the mages. :)
031996: Saffrin added it to the new mage guild

Note: This bed is privacy!  But it can be copied by wizards :*)
					    (c) Whisky
   ----------------------------------------------------------------------- */


/* defines */
#define aa add_action
#define TP this_player()
#define TPN TP->query_name()
#define TPG TP->query_gender() 
#define TPP TP->query_possessive()
#define OPN ob->query_name()
#define OPG ob->query_gender()
#define OPP ob->query_possessive()

inherit "/room/room"; 

string *s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8,*s9,*s10;
int open;
object scroll;

int wanimate(); 
void tell_all_but(object who,string str); 
int do_read(string arg);

reset(room)
{
    if (!intp(open)) open =0;
    ::reset(room);

    if (!scroll)
    {
	scroll = clone_object("/players/whisky/obj/recall_scroll");
	move_object(scroll,this_object());
    }
    short_desc = ("Cardinal's Sins");
    long_desc =(
      "You are in Cardinal Sins, a special room in the Mage Tower for "+
      "pleasure.  There is a soft, fluffy bed shaped like a heart, resting "+
      "against the north wall.  A fireplace with a crackling fire is along the west "+
      "wall.  There is a sign resting on the mantle of the fireplace.  "+
      "To set your title in here, simply type 'title <string>' and your new title "+
      "will be set.  "+
      "This service will cost you 10000 coins.\n");

    items= ({
      "bed","A heart shaped bed that looks soft and fluffy",
      "pillows","They are soft and red pillows",
      "carpet","A red satin carpet",
      "walls", "Soft red walls",
      "fireplace", "A fireplace with a warm crackling fire",
      "sign", "There is something written on it",
      "mantle", "The mantle of the fireplace with a sign resting on it",
    });
    dest_dir = ({
      "/players/saffrin/guild/rooms/hall3", "south",
    });

    set_light(1);

    s1 = ({ " pussy"," finger"," pussy"});
    s2=({" pussy"," penis"," pussy"});
    s3=({" wet open pussy"," dick"," wet open pussy"});
    s4=({" in"," on"," in"});
    s5=({" pussy"," penis"," pussy"});
    s6=({" tits"," hairs"," tits"});
    s7=({" wet pussy"," mouth"," wet pussy"});
    s8=({" clit"," penis"," clit"});
    s9=({" slippery pussy"," hard on"," slippery pussy"});
    s10=({" tits"," hairs"," hairs"});
}



int do_read(string arg) {
    if (arg!="sign") return ( 0 ); 
    open = 1;
    if (open)
    {
	write(
	  "This is the 'private' mage pleasure room: \n"+
	  "Extra commands:  sleep, love, lick, animate, kissall,\n"+
	  "                 orgasm, fuck, assfuck, sit, spread,\n"+
	  "                 suck, back, breastfuck, finger.\n"+
	  "This room can be used for partysex as well.\n"+
	  "This room is private, so use it at your own risk!!! (or fun) \n\n"+
	  "                                 Cardinal the Sinner\n\n");
    } else 
	write("You see nothing special.\n"); 
    return ( 1 );
}


int do_sleep()
{
    write("You curl up on the bed and fall asleep.\n");
    say(TPN+" curls up on the bed and falls asleep.\n");
    return 1;
}

void tell_all_but(object who,string str) {
    object *o;
    int i;

    o=all_inventory();
    for(i=0; i<sizeof(o); i=i+1) {
	if((living(o[i]))&&(o[i]!=TP)&&(o[i]!=who)) {
	    tell_object(o[i],str);
	}
    }
}

int do_assfuck(string arg) {
    object ob;

    if(!arg) return 0;

    if(!(ob=present(arg)) || (!living(ob))) return 0;
    write("You turn "+OPN+" on "+OPP+" back and slowly stick your"+s1[TPG]+
      " into\n"+OPN+"'s ass.\n"+OPN+" makes a short shout and then cries: "
      + "Uhhhhh "+TPN+" give\nme more of that, I love that Ahhhhhhh!\n");
    tell_object(ob,TPN+" turns you on your back and slowly sticks "+TPP+s1[TPG]
      + "\ninto your ass. First it hurts a bit but then you get a "+
      "wonderful\nfeeling Ahhhhhhhh!\n"+TPN+" fondles your"+s2[OPG]+
      " while moving slowly in your ass and\ncries in full erection:"
      + " I love you "+OPN+"!\n");
    tell_all_but(ob,TPN+" turns "+OPN+" on "+OPP+" back and slowly sticks\n"+
      TPP+s1[TPG]+" into "+OPN+"'s ass.\n"+OPN+" makes a short "+
      "shout and then cries: Uhhhhhh "+TPN+" give\nme more, I love"+

      " that, Ahhhhhhhh!\n");
    return 1;
}


int do_love(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You are making mad, passionate love with "+OPN+".\n");
    tell_object(ob,TPN+" says: OOOOOOHHH! Make love to me "+OPN+"!\n"+TPN+
      " says: Uhhhhhhhhh! give me hot sex, fuck me.\n");
    tell_all_but(ob,TPN+" is making love with "+OPN+"\n"+TPN+" shouts: make "+
      "love to me "+OPN+". Ohhhhhhh, give me hot\nsex!\n");
    return 1;
}

int do_fuck(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You are wildly fucking "+OPN+".\n");
    tell_object(ob,TPN+" says: OOOOHHHHH! Make love to me "+OPN+"!\n"+TPN+
      " cries: Fuck me Ahhhhhhhhhhh. Give me your hot body.\n");
    tell_all_but(ob,TPN+" says: OHHHHHHHHHH, make love to me "+OPN+"\n"+
      "Ahhhhhhhhhhhh! Give me your hot body.\n");
    return 1;
}

int do_sit(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You slide down on "+OPN+"'s mighty"+s3[OPG]+".\n"+OPN+" says: "+
      "OOHHH! Please don't stop now, "+TPN+"!\n");
    tell_object(ob,TPN+" jumps up and down on your"+s3[OPG]+".\n"+TPN+" says: "
      + "OOHH! I just can't let it be, "+OPN+"!\n");
    tell_all_but(ob,TPN+" slides down on "+OPN+"'s mighty"+s3[OPG]+".\n"+OPN+
      " says: OHHHHHHH! Please don't stop now!\n"+TPN+" jumps up "+
      "and down on "+OPN+"'s"+s3[OPG]+" and shouts:\nOhhhhhh! I "+
      "just can't let it be!\n");
    return 1;
}

int do_spread(string arg) {
    object ob;


    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You spread your legs wider wanting "+OPN+" to thrust"+s4[TPG]+
      " you, deep.\n"+OPN+" says: OOHHH, "+TPN+"!\n");
    tell_object(ob,TPN+" spreads "+TPP+" legs wider wanting you to thrust"+
      s4[TPG]+", deep.\n"+TPN+" says: "+OPN+", fuck me! now!\n");
    tell_all_but(ob,TPN+" spreads "+TPP+" legs wider wanting "+OPN+"\n"+
      "to thrust"+s4[TPG]+"!\n"+TPN+" shouts: OHHHHHHH! Fuck me "+
      "now!\n");
    return 1;
}

int do_suck(string arg) {
    object ob;


    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You take "+OPN+"'s"+s5[OPG]+" in your mouth\nand start to suck "+
      ob->query_objective()+" faster and faster.\n"+OPN+" moans: Give me "+
      "more, UHHHHHHHHHHHHHHH!\n");
    tell_object(ob,TPN+" takes your"+s5[OPG]+" in "+TPP+" mouth\nand sucks you"
      + " faster and faster.\nYou feel like you are going to explode, "
      + "Uhhhhhhhhhhhhhhh!\n");
    tell_all_but(ob,TPN+" takes "+OPN+"'s"+s5[OPG]+" into "+TPP+" mouth\nand "+
      "starts to suck "+ob->query_objective()+" faster and "+
      "faster!\n"+OPN+" moans: Give me more, UHHHHHHHHHHHHHHH!\n");
    return 1; 
}

int do_back(string arg) {

    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You go on fucking "+OPN+" from this rear point.\nYou squeeze "+OPP+
      " buttocks harder for every push you give "+ob->query_objective()+
      ".\n");
    tell_object(ob,TPN+" goes on fucking you from the rear.\n"+
      capitalize(this_player()->query_pronoun())+" squeezes your "+
      "buttocks for every push "+this_player()->query_pronoun()+
      " gives you.\n");
    tell_all_but(ob,TPN+" fucks "+OPN+" from "+OPP+" rear point.\n"+
      capitalize(this_player()->query_pronoun())+" squeezes "+OPP+
      " buttocks harder for every push "+
      this_player()->query_pronoun()+" gives "+ob->query_objective() 
      + ".\n"+OPN+" shouts: UIHHHHHHHHHH! I love that!\n");
    return 1;
}

int do_breastfuck(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You turn "+OPN+" around so that "+ob->query_pronoun()+" lies on "+
      OPP+" back.\nAfter that you place yourself on "+OPN+"'s stomach.\n"+
      "You put your"+s3[TPG]+" between "+OPP+s6[OPG]+" and squeeze them "+
      "together.\nThen you start to move your"+s3[TPG]+" between "+OPP+
      s6[OPG]+".\n");  
    tell_object(ob,TPN+" places "+this_player()->query_objective()+"self upon"+ 
      " you and puts "+TPP+s3[TPG]+" between your\n"+s6[OPG]+". You"+
      " can feel "+TPP+s3[TPG]+" pulsate as it ramages between your"+
      s6[OPG]+".\nAll you can think of is what it would be like to "+
      "suck it...\n");
    tell_all_but(ob,TPN+" turns "+OPN+" around so that "+ob->query_pronoun()+
      " lies on "+OPP+" back.\nAfter that "+
      this_player()->query_pronoun()+" places "+
      this_player()->query_objective()+"self on "+OPN+"'s "+
      "stomach\nand puts "+TPP+s3[TPG]+" between "+OPP+s6[OPG]+
      " and squeezes them together.\n"+TPN+" moans: UHHHHHHHHH! I "+
      "love that kind of fuck!\n");
    return 1;
}

int do_finger(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You put your finger into "+OPN+"'s wet"+s7[OPG]+".\nYou slowly "+
      "start to move the finger in and out.\nYou softly rub "+OPN+"'s"+
      s8[OPG]+" till "+ob->query_pronoun()+" moans.\nAs you do that "+OPN+
      " starts to moan loudly.\n");
    tell_object(ob,TPN+" puts "+TPP+" finger into your wet"+s7[OPG]+"\nand "+
      "rubs softly over your hot"+s8[OPG]+"!\nA wonderful feeling "+

      "spreads in your abdomen as "+this_player()->query_pronoun()+
      " starts\nto move the finger in and out... You start to moan "+
      "loudly.\n");
    tell_all_but(ob,TPN+" puts "+TPP+" finger slowly into "+OPN+"'s wet"+
      s7[OPG]+"\nand starts to move "+TPP+" finger slowly in and "+ 
      "out.\nThen he rubs softly over "+OPP+s8[OPG]+"!\n"+OPN+
      " begins to moan loudly: UHHHHHHIIIIIII, give me more, fuck\n"
      + "me!\n");
    return 1;
}

int do_lick(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You lick "+OPN+"'s"+s9[OPG]+" like a tiger!\n"+OPN+" shouts: "+
      "IHHHHHHHHHHH, I get it, fuck me now!\n");
    tell_object(ob,TPN+" licks your"+s5[OPG]+" teasing you with "+TPP+
      " tongue!\n"+TPN+" makes circles with "+TPP+" tongue around"+
      " your"+s8[OPG]+" and\nlicks all of your hot liquid!\n");
    tell_all_but(ob,TPN+" licks "+OPN+"'s"+s9[OPG]+" like a tiger teasing\n"+
      ob->query_objective()+" with "+TPP+" tongue and circling "+
      "around "+OPP+s8[OPG]+"!\n"+OPN+" shouts: IHHHHHHHHHH, I get"+
      " it, fuck me now!\n");
    return 1;
}

int do_animate() {
    if(TPG==1) {
	return wanimate();
    }
    write("You lie yourself down on the soft pillows.\nYou take your penis in"+
      " in your one hand and with\nthe other hand you begin to softly wank"
      + " your penis.\nYou move your hands all over your body, to show in "+


      "which\nerection you are!\n");
    say(TPN+" lies himself down on the soft pillows, puts one hand at\nhis "+
      "penis and wanks himself softly. With the other hand he plays with\n"+
      "his hot balls. Some sperm is running out the top of his\nhard "+
      "penis. He softly moves his hands all over his body\nto return to his "
      + "hot place: his stiff penis and to wank him\nslowly. You feel like he "
      + "is in full erection and you see\nhis beautiful penis getting bigger "+
      "and bigger.\n");
    return 1;
}


int wanimate() {
    write("You lie yourself down on the soft pillows.\nYou spread your hot"+
      " legs and begin to softly rub your\nwhole body. You play with your "+
      "nable and your beautiful tits\nand then you put one hand at your "+
      "hot pussy and one finger\ninto your fantastic ass. You begin to "+
      "softly fondle your\nmagnificent pussy. You spread it with two "+
      "fingers and with the\nother fingers you rub your clitoris softly. "+
      "You get wetter and\nwetter. An erotic feeling warms your body. "+
      "You turn back to your\ntits and to fondle your beautiful pussy "+
      "and to show the others what\nkind of erection you have!\n");
    say(TPN+" lies herself down and spreads her hot legs. Then she begins\n"+
      "to softly rub her entire body. She plays with her nable,\nher "+
      "beautiful tits and then she puts one finger into her hot ass\nand "+
      "with the other hand she spreads her pussy and rubs her hot\n"+
      "clitoris. You see sweat and hot liquid running down over her legs "+
      "and you\n see that her muscles shake full of erection. Her mouth is "+
      "wide open\nwaiting for something. You know: she wants it all and "+
      "you can see\nher hot body with the fingers in both her hot holes "+
      "moving up and\ndown!\n");
    return 1;
}

int do_kissall(string arg) {
    object ob;

    if(!arg) return 0;
    if(!(ob=present(arg))||(!living(ob))) return 0;
    write("You kiss all over "+OPN+"'s body.\n"+OPN+" moans: IHHHH, I want "+
      "more, fuck me please!\n");
    tell_object(ob,TPN+" kisses you all over your body!\n"+TPN+" says: I "+
      "love your wonderful"+s7[OPG]+"\nand your beautiful"+s10[OPG]+", "+
      OPN+".\n");
    tell_all_but(ob,TPN+" kisses and licks "+OPN+" all over her body.\n"+OPN+
      " moans: UHHHHH! I want more!\n"+TPN+" says: I love your "+
      "wonderful"+s7[OPG]+" and your beautiful"+s10[OPG]+"!\n");
    return 1;
}

int do_orgasm() {
    write("UHHHHHHHIIIIIIIIIIIIIIIIIII! your under-muscles jerk wildly!\nYou "+
      "nearly fall into a coma. Ahhhhhhhhhhhhh!\nYou burst into a "+
      "wonderful orgasm. It seems to last forever.\n");
    say(TPN+" bursts into a wonderful orgasm!\n"+TPN+" cries full of "+
      "erection: Ihhhhhhhhhhhhhhhhhhh!\nand gets wet all over.\n"+TPN+
      " cries: Uhhhhhhhhhhhhhh, you are wonderful!\n");
    return 1;
}


init()
{
    string file;

    write("As you enter the room, you are caught in a cloud of rose perfume.\n");
    this_player()->set_smell(capitalize(this_player()->query_pronoun())+
      " smells like fresh roses, very sexy!");
    aa("show_stats","show_stats");
    aa("do_sleep","sleep");
    aa("do_love","love");
    aa("test","test");
    aa("do_lick","lick");
    aa("do_kissall","kissall");
    aa("do_animate","animate");
    aa("do_orgasm","orgasm");
    aa("do_fuck","fuck");
    aa("do_assfuck","assfuck");
    aa("do_sit","sit");
    aa("do_spread","spread");
    aa("do_suck","suck");
    aa("do_back","back");
    aa("do_breastfuck","breastfuck");
    aa("do_finger","finger");
    aa("do_title","title");
    aa("do_read","read");
    ::init();
}

int
do_open()
{
    if (interactive(TP) && TP->query_immortal()) /* only immortals can ! */
	open = 1; init();
    return 1;
}

int
do_close()
{
    if (interactive(TP) && TP->query_immortal())
	open =0; init();
    return 1;
}
/* testing for parser */
clean_up(arg)    
{
    log_file("parser.test","Whisky's workroom was cleaned at: "+ctime(time())+"\n");
    return 1;
}
test()
{
    object shad;
    shad = clone_object("/players/moonchild/deep_forest/inv_shad");
    shad->start_shadow(this_player());
    write("ok\n");
    return 1;
}

show_picture()
{
    cat("/players/whisky/guild/room/pict.h");
    return "";
}
int do_title(string arg)
{
    if (!arg)
    {
	notify_fail("Set which title ?\n");
	return 0;
    }
    else if (strlen(arg) > 30)
    {
	notify_fail("The maximun line length of your title is 30.\n");
	return 0;
    }
    else if (this_player()->query_money() < 10000)
    {
	notify_fail("Sorry, setting the title would cost you 10000 coins.\n");
	return 0;
    }
    this_player()->set_title(arg);
    this_player()->add_money(-10000);
    write("You title is now: "+arg+"\n");
    return 1;
}
