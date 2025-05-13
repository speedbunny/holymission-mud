inherit "obj/treasure";
/*   Created by Colossus@HM 091593    */

#include "/players/colossus/rooms/debug.h"

#define LPAGE 20

string text_file;
string title;
string help_text;
int current_page;

reset(arg){
    ::reset(arg);
    if(arg) return;
    current_page=0;
    set_name("book");
    title="An untitled work";
    set_short("Book from the Wizards' library");
    set_long(
      "It is a huge book bound in soft leather. The pages seem to glow with a\n"+
      "magical aura and on the cover is the title.\n"+
      "Title is: "+title+"\n"+
      "Type 'help book' for help and read the book.\n");
    help_text = "You may 'open', 'close', 'turn [page] [<num>]', and 'read'"+
    "this book.\n";
}

drop(){
    write("As you release the book it fades into thin air.\n");
    say("As "+this_player()->query_name()+
      " releases a book, it fades into thin air.\n");
    destruct(this_object());
    return 1;
}


init(){
    add_action("open", "open");
    add_action("close", "close");
    add_action("read_book", "read");
    add_action("turn_page", "turn");
    add_action("help_book", "help");
}

int open(string str){
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You have to get it first!\n");
	return 1;
    }
    if (current_page > 0) {
	write("The book is already open at page " + current_page + ".\n");
	return 1;
    }
    current_page = 1;
    write("Ok.\n");
    say(this_player()->query_name()+" opens a book\n");
    return 1;
}                          
int close(string str)
{
    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	return 0;
    }
    if (current_page == 0) {
	write("It is already closed.\n");
	return 1;
    }
    current_page = 0;
    write("Ok.\n");
    say(this_player()->query_name()+" closes a book.\n");
    return 1;
}

void set_text_file(string file) {
    text_file = file;
}                    
set_title(string arg) {
    title = arg;
    set_long(
      "It is a huge book bound in soft leather. The pages seem to glow with a\n"
      +
      "magical aura and on the cover is the title.\n"+
      "Title is: "+title+"\n"+
      "Type 'help book' for help and read the book.\n"); 
}

set_help_text(string arg) {
    help_text = arg;
}

int read_book(string str)
{
    int catted;  /* amount catted out, to tell when we're done */
    int lines, pages;
    if (!id(str) && str != "page" || !text_file)    {
	if (debug) write("exiting because of !str or !text_file\n");
	return 0;
    }
    if (current_page == 0) {
	write("It is closed.\n");
	return 1;
    }
    if (!text_file) {
	write("  *** END OF BOOK ***\n");    
	return 1;
    }
    lines = file_size(text_file);
    if (lines <= 0) {
	write("  *** END OF BOOK ***\n");
	return 1;
    }
    pages = lines / LPAGE;
    if (lines % LPAGE) pages++;
    say(this_player()->query_name()+" reads a book.\n");
    catted = 0;
    if (current_page == 1) {
	catted = cat(text_file, 1, LPAGE);
    } else
	catted = cat(text_file, ((current_page-1)*LPAGE)+1,LPAGE);
    if (catted != LPAGE || current_page == pages) {
	write(" *** END OF BOOK *** \n");
    } else {
	write(" *** Page "+current_page+
	  " --                       *turn* page to cont.\n");
    }                                                      
    return 1;
}

turn_page(str){
    int page_num;
    string stuff;
    int lines, pages;

    if(current_page==0){
	write("The book is closed.\n");
	return 1;
    }
    if(!str || str == "page"){
	str = "page "+(current_page+1);
    }
    if(sscanf(str, "%s %d\n", stuff, page_num)==2){
	lines = file_size(text_file);
	pages = lines / LPAGE;
	if (lines % LPAGE) pages++;
	if(page_num>pages || page_num <1){
	    write("There are not that many pages!.\n");
	    return 1;                           
	}
	current_page = page_num;
	write("You turn to page "+page_num+".\n");
	say(this_player()->query_name()+" turns to page "+page_num);
	return 1;
    }
    write("Invalid page number, format: turn page <num>\n");
    return 1;
}

help_book(str) {
    if (!str || !id(str))
	return 0;
    write(help_text);
    return 1;
}

query_title() { return title; } 
