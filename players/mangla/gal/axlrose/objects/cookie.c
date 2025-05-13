/* Sonja's Chocolate Chip Cookie */
inherit "/obj/food";

string *msg;
void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
	msg = ({
	  "Quickly chomping the cookie, you crumble it all over your face and \n"
	  +"hands.  *oink* *oink* *oink*\n",
	  "With finesse, you eat the chocolate chip cookie with gusto!\n",
	  "You hurryingly gobble up the chocolate chip cookie in one gulp!! *burp*\n",
	  "Delicately savoring each morsel, you melt with every bite of dark, deep \n"
	  +"rich chocolate.  *sigh happily*\n"
	});
	set_name("chocolate chip cookie");
	set_alias("cookie");
	set_short("chocolate chip cookie");
	set_long("A dark, deep, rich chocolate chipped cookie lightly colored brown.\n");
	set_eating_mess(" chomps down a chocolate chip cookie, hoarding it greedily.\n");
	set_strength(10);
	set_value(20);
	set_weight(1);
    }
}

mixed eat(string arg)
{
    eater_mess = msg[random(4)];
    return ::eat(arg);
}
