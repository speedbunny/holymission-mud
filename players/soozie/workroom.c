#define NAME "soozie"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
	/* first we need some light in here */
	set_light(1);

	/* then lets set a short description in case we are in brief-mode */
	short_desc = "workroom";

	/* now the long standard room description */
	/* change this to fit your style *grin* */
	long_desc=
	"Welcome, traveller!\n" +
	"As you enter this room, you are struck with an immense sense of peace\n" +
	"and tranquility.  The walls are of heavy stone, and are covered with many\n" +
	"tapestries.  A large mahogany bookshelf stands in one corner, packed with\n" +
	"ancient books, scrolls, and many illuminated manuscripts.  Herbs and\n" +
	"medicinal plants hang on the walls and from the wooden rafters above.  It\n" +
	"smells wonderful in here, but you know that there's more to this\n" +
	"atmosphere than plants.  As you look around you see the tools of one who\n" +
	"cares deeply for the earth...perhaps even worships the earth.  There is a\n" +
	"large black marble fireplace opposite the bookshelf, and it is always\n" +
	"lit.  Near the fireplace, but against the wall is a table, with many\n" +
	"objects on it.  The velvet and wood furniture is the most comfortable you\n"
	"have ever sat in!  Hope you enjoy your stay here!!\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "room/post", "post",
	  "room/church", "church",
	  "room/adv_guild", "guild", 
	});

	/* here could follow some item descriptions, like ...*/
	items=({ 
	  "walls","They emanate warmth and are covered with tapestries.",
	  "tapestries","Full of color, they depict women surrounded by frolicking animals.",
	  "animals","You see bunnnies, dogs and unicorns playing in the woods.",
	  "books","Many are ancient spellbooks dating back hundreds of years!",
	  "scrolls","Tattered and worn, these scrolls hold many secrets.",
	  "manuscripts","These tiny books contain vellum pages, bright pictures and valuable lessons.",
	  "herbs","Soozie likes to grow and dry its own herbs both for food and healing.",
	  "plants","Everything from roses to aloe grow and dry here.",
	  "tools","Here are many tools used for planting, such as a small spade and some pots.",
	  "fireplace","A large fireplace with a steaming cauldron hanging in it.",
	  "cauldron","Don't poke around in there! It's Soozie's laundry!!",
	  "table","An ornate mahogany table, or perhaps an altar, which many objects sit upon.",
	  "objects","Here stand a golden chalice of water, an earthen bowl of sand and salt, two white candles, which are always lit, and a small censer of incense which is also always lit.",
	  "velvet","Ahh...dark red plush velvet...how cozy!",
	  "furniture","Consisting of many pieces, it looks very cozy, not to mention overstuffed and comfortable!",
	});
	/* Properties can be set like the following */
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	/* Smell is set like this... */
	smell = "This place is a bit dusty";
    }
}

init()
{
    ::init();
}
