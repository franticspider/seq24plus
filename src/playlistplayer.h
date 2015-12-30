/*
 * playlistplayer.h
 *
 *  Created on: 30 Dec 2015
 *      Author: sjh
 */

#ifndef SRC_PLAYLISTPLAYER_H_
#define SRC_PLAYLISTPLAYER_H_



#include <gtkmm/widget.h>
#include <gtkmm/window.h>



class playlist_player:public Gtk::Window
{

public:
	playlist_player();
	virtual ~playlist_player();


	void init_before_show();
};

#endif /* SRC_PLAYLISTPLAYER_H_ */
