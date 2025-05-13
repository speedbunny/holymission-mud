inherit "/room/room";
#include "/players/colossus/rooms/debug.h"


#define NULL (string)0
#define SAVE_FILE "/players/colossus/data/library_list"
int loaded, i;
int loaded, i;

string *authors, *areas, *guilds, *quests;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    loaded=0;
    set_light(1);
    short_desc = "Wizards' library";
    long_desc =
    "This is the wizards' library where each wizard publishes his or her ideas\n"+
    "on what he/she is coding for other wizards' references. There is a sign here\n"+
    "that you can read.\n";

    dest_dir = ({
      "players/colossus/workroom", "col",
    });

    items = ({
      "sign", "A sign that you should read detailing library rules",
    });
}

void init(){
    ::init();
    add_action("read_sign", "read");
    add_action("list_books", "list");
    add_action("checkout_book", "checkout");
    add_action("return_book", "return");
    add_action("make_book", "publish");
    add_action("review", "review");
}

int read_sign(string arg){
    if(!arg || arg!="sign") return 0;
    write(
      "Use the following commands in this room:\n"+
      "\n"+
      "list					: list the authors of the books here.\n"+
      "checkout <name> <a|q|g>			: get <name>'s book down.\n"+
      "publish <a|q|g> <file>			: create a book in your name,\n"+
      "					  using <file> as filename\n"+
      "					  for its text.\n"+
      "review					: review the files you have set\n\n"+
      " <a|g|q|> are abbreviations of <area|guild|quest>\n"+
      " <file> may be relative to your /players directory\n"+
"\n"+
      " Example of checking out books and publishing them using 'guest' as <name>\n"+
      " checkout guest a  -  checks out area book published by guest.\n"+
      " publish guest a /players/guest/area_book - publishes area book if the\n"+
      "					      filename exists\n"+
      "\n");
    return 1;
}

list_books(){
    int j, num;
    if(!loaded) load_list();

    num=sizeof(authors);
    write("There "+(num==1 ? "is":"are")+" "+num+" author"+
    (num==1?"":"s")+" published here:\n");
    write("Author                    Area  Quest  Guild.\n");
    write("=======                   ====  =====  =====\n");
    for (i = 0; i < sizeof(authors); i ++ ) {
	write(authors[i]); for (j=strlen((string)authors[i]);j<26;j++) write(" ");
	if (debug)write(areas[i]+" ");
	else write(areas[i]?" Y    ":"      ");
	if (debug)write(quests[i]+" ");
	else write(quests[i]?"  Y    ":"       ");
	if (debug)write(guilds[i]+" ");
	else write(guilds[i]?"  Y    ":"       ");
	write("\n");
    }
    return 1;
}

string real_which(string check){
    check=capitalize(check);
    switch(check){
    case "G": check="Guild"; break;
    case "A": check="Area"; break;
    case "Q": check="Quest"; break;
    default:
	write("No such book, please try again.\n");
	return "";
    }
    return check;
}

string modify_path(string file, string author){
    string temp;
    if(file[0]=='/'){
	if(sscanf(file,"/players/"+lower_case(author)+"/%s",temp)!=1){
	    write("The file must be in your /players directory!\n");
	    return "";
	}
	else return file;
    } else return "/players/"+lower_case(author)+"/"+file;
}

checkout_book(string arg){
    int index;
    string which, author, text;
    object book;
    if(!loaded) load_list();
    if(!arg || arg==""){
	write("check out whose book?\n");
	return 1;
    }
    if(!authors){
	write("There aren't any books!\n");
	return 1;
    }
    if(sscanf(arg, "%s %s",author, which)!=2){
	write("Usage: checkout <author> <area|quest|guild>\n");
	return 1;
    }
    author = capitalize(author);
    if ((index = member_array(author,authors)) == -1) {
	write("Check out whose book?\n");
	write("Use 'list' to find out what books are available\n");
	return 1;
    }
    which = real_which(which);
    switch(which) {
    case "Area"  : text = areas[index];
	break;
    case "Guild" : text = guilds[index]; 
	break;
    case "Quest" : text = quests[index];
	break;
    default:
	write("Appropriate books are 'area', 'quest' or 'guild'.\n");
	return 1;
    }

    if (!text || text == "0") {
	write(author+" does not have a "+which+" book published, use 'list'.\n");
	return 1;
    }

    book = clone_object("/players/colossus/obj/generic_book");
    book->set_text_file(modify_path(text,author));
    book->set_title(authors[index]+"'s "+which+" Book");
    transfer(book, this_player());
    write("You check out a book titled '"+book->query_title()+"'.\n");
    return 1;
}

int return_book(string arg) {
    write("Sorry, returning the book is not yet implemented\n"+
      "Please just dest it to get rid of it.\n");
    return 1;
}

int alpha_sort(string a, string b) {
    return a>b;
}

void load_list() {
    string contents;
    string *arr, area,quest,guild;
    int foo;

    contents = read_file(SAVE_FILE);
    if (!contents) return;
    if (debug) write(contents);
    arr = explode(contents,"\n");


    if (!arr) return;  
    i = sizeof(arr)-1;
    authors = allocate(i);
    areas = allocate(i);
    guilds = allocate(i);
    quests = allocate(i);

    for (i = 0; i < sizeof(arr)-1; i++) {
	sscanf(arr[i],"%s %s %s %s",authors[i],area,quest,guild);
	if (sscanf(area,"%d",foo)==1) areas[i] = NULL; else areas[i] = area;
	if (sscanf(quest,"%d",foo)==1) quests[i] = NULL; else quests[i] = quest;
	if (sscanf(guild,"%d",foo)==1) guilds[i] = NULL; else guilds[i] = guild;
    }

    loaded = 1;
}

void save_list() {
    string * lines;
    lines = allocate(sizeof(authors));
    if (!authors) return;
    for (i = 0; i < sizeof(authors); i ++) {
	lines[i] = authors[i]+" "+areas[i]+" "+quests[i]+" "+guilds[i];
    }
    lines = sort_array(lines,"alpha_sort",this_object());
    rm(SAVE_FILE);
    for (i = 0; i < sizeof(lines); i ++) {
	write_file(SAVE_FILE,lines[i]+"\n");
    }
    loaded = 0;
}

int make_book(string arg) {
    int index;
    string which,where,author;
    if (!arg || arg == "" || (sscanf(arg,"%s %s",which,where)!=2) ) {
	write("You need to specify which book and a file to use as the text.\n");
	return 1;
    }
    which = real_which(which);
    if (debug) write("DEBUG: publishing "+which+" which is file "+where+".\n");
    author = capitalize((string)this_player()->query_real_name());
    if (file_size(modify_path(where,author)) <= 0) {
	write("Invalid file name.  The file must exist and have something\n"+   
	  "in it (ie. size > 0) to be valid.\n");
	return 1;
    }
    if (!loaded) load_list();
    if (!authors) {
	/* first author to publish */
	if (debug) {
	    write("List was empty!\n");
	    write("Adding "+author);
	}
	authors = ({author});
	areas = ({0});
	quests = ({0});
	guilds = ({0});
	switch(which) {
	case "Area": areas[0] = where; break;
	case "Quest" : quests[0] = where; break;
	case "Guild" : guilds[0] = where; break;
	}
	if (debug)
	    write(" "+areas[0]+" "+quests[0]+" "+guilds[0]+".\n");
	save_list();                                              
	return 1;
    }
    index = member_array(author,authors);
    if (index == -1) {
	/* first book by this author */
	if (debug) write("first book by this author, not first book ever.\n");
	authors += ({author});
	switch(which) {
	case "Area": areas += ({where});quests+=({0});guilds+=({0}); break;
	case "Quest" : quests += ({where});areas+=({0});guilds+=({0}); break;
	case "Guild" : guilds += ({where});areas+=({0});quests+=({0}); break;
	}
    } else {
	/* author changing their book ! */
	switch(which) {
	    if (debug) write("modifying existing entry!\n");
	case "Area": areas[index] = where; break;
	case "Quest" : quests[index] = where; break;
	case "Guild" : guilds[index] = where; break;
	}
    }
    save_list();                                         
    return 1;
}

varargs int review(string arg) {
    string author;
    int index;


    if(arg && this_player()->query_level()>=35)
	author = capitalize(arg);
    else
	author = capitalize((string)this_player()->query_real_name());

    if (!authors || (index = member_array(author,authors))==-1) {
	write("You don't have any books published.\n");
	return 1;
    }

    write(author+" has published: \n");
    if (areas[index]) write(" An Area Book: "+areas[index]+".\n");
    else write(" No Area Book.\n");
    if (quests[index]) write(" A Quest Book: "+quests[index]+".\n");

    else write(" No Quest Book.\n");
    if (guilds[index]) write(" A Guild Book: "+guilds[index]+".\n");
    else write(" No Guild Book.\n");
    return 1;
}                       
