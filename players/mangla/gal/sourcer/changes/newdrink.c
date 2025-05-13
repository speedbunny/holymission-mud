/*
 * new Object drink to use inherit features
 */

#define LOG(x) log_file("/drinks.log",file_name(this_object())+"### "+x+"\n")
#define TP this_player()

/****** variables *******/
int full;           /* still something in it ? */
int food;           /* Does it satiate too ? */
int heal;           /* The ammount of healing */
int value;      
int strength;       /* the power of the drink */
int pub_drink;      /* a flag for pubs (no leave) */
string short_desc;  /* Short description */
string long_desc;   /* Long description */
string name,alias,alt_name;  /* The names */
string message;     /* the drink message */
string container;   /* the name of the empty container */
int weight;         /* weight of the drink */

/****** prototypes  *****/
void set_empty();

/*
 *   RESET
 */
void reset(int arg)
{
	if(arg) return;
	
    full = 1;
    food = 1;
    heal = 0;
    value= 0;
    strength = 0;
	pub_drink = 0;
	short_desc = "Drink";
	long_desc  = "Base for Drinks\n";
	name = "drink";
	alias = "drink";
    message = "Gluck Gluck Gluck";
	container = "bottle (empty)";
}

/*
 * INIT
 */
void init()
{
	add_action("_drink","drink");
}


/* USERDOC:
 * set_value
 * Format: set_value(s)
 * Example: set_value("beer#A beer#It tastes awful#12#5")
 * This function sets the entire drink. The arguments are seperated by '#', and
 * there are 5 of them. The first argument is the name, the second is the short
 * description, the third is the message displayed when the drink is drunk (this
 * message should not have a '.'), the fourth is the value of the item and the
 * fifth is the strength of the drink.
 */
int set_value(string str)
{
    if (sscanf(str, "%s#%s#%s#%d#%d#%d", name, short_desc, message,
    heal, value, strength) != 6)
        return 0;
    return 1;
}


/* USERDOC:
 * set_pub
 * Format: set_pub()
 * This function makes this drink one that can't be removed from pubs.
 */
void set_pub() { pub_drink = 1; }


/* USERDOC:
 * set_food
 * Format: set_food(i)
 * Example: set_food(1)
 * This function indicates this drink as a food. This should be used if there is
 * something edible in the drink as well.
 */
void set_food(int fo)
{
  if (intp(fo))
      food = fo;
}

 
/* USERDOC:
 * query_food
 * Format: i=query_food()
 * Returns the ammount of food in the drink.
 */
int query_food()
{
  if (intp(food)) return food;
  return 0;
}   
 
/* USERDOC:
 * query_drink
 * Format: i=query_drink()
 * Always returns 1, to indicate this item as a drink.
 */
int query_drink()
{
  return 1;
}

/* 
 * WEIGHT
 */
int query_weight()
{	
	return weight;
}

void set_weight(int i) 
{
	weight = i<0 ? 0 : i;
}

/*
 * ID
 */
int id(string me)
{
	if(me=="drk2") LOG("<me=drk2>");
	return( me=="bottle" || me==name || me==alias || (me=="drk2" && pub_drink));
}

/*
 * SHORT
 */
string short()
{
	if(full) 
	{
		if(strlen(short_desc)) return short_desc;
	    else if(strlen(name)) return name;
	}
	if(strlen(container)) return "An empty "+container;
	else if(strlen(name)) return "An empty "+name;
	else return "An empty bottle";
}

/*
 * QUERY_VALUE
 * The shop only buye empty bottles	
 */
int query_value()
{
	if(!full) return 10;
	return 0;
}

/*
 * LONG
 */
void long()
{
	if(long_desc && strlen(long_desc))
		write(long_desc);
    else write(short()+".\n");
}

/*
 * _DRINK  .. called by the add_action
 */
int _drink(string me)
{
	if(!stringp(me) || !id(me) || !full || !objectp(this_player()))
		return 0;

	if(strength > (2+TP->query_leve()+TP->query_legend_level()))
	{
		write("You sputter liquid all over the room.\n");
		say(TP->query_name()+" tries a "+name+
			" but coughs and sputters all over the room.\n");
		set_empty();
	}
	if(!TP->drink_alco(strength) && !TP->query_npc())
		return 1;
	
	TP->heal_self(heal);
	write(message + ".\n");
	say(TP->query_name()+" drinks "+name+".\n",TP);
	set_empty();
	return 1;
}

/*
 * SET EMPTY
 * empty the drink
 */
void set_empty()
{
	full = 0;
	food = 0;
	name = "bottle";
	alias = "empty";
	short_desc += " (empty)";
	if(strlen(long_desc)) long_desc+="It is empty.\n";
}

/*
 * GET
 */
int get()
{
	return 1;
}

/* 
 * SET NAME
 */
void set_name(string str)
{
	name = str;
}

/*
 * SET ALIAS
 */
void set_alias(string str)
{
	alias = str;
}

/*
 * SET ALT NAME
 */
void set_alt_name(string str)
{
	LOG("<alt_name>");
	alt_name = str;
}

string query_name()
{
	if(full) return name;
	return "empty bottle";
}
		













