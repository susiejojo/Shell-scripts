#!/bin/zsh
#make sure you are saving the downloaded playlist to ~/Music/Playlist/
youtube-dl --verbose -citk https://www.youtube.com/watch\?v\=Ho32Oh6b4jc\&list\=PLnl9aWBgMdHuBi1sTDhWG7I9KoGJqsnxS\&index\=3
vlc ~/Music/Playlist/*.mp4
 
