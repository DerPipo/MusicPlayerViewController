//
//  BeamMusicPlayerViewController.h
//  Part of MusicPlayerViewController
//
//  Created by Moritz Haarmann on 30.05.12.
//  Copyright (c) 2012 BeamApp UG. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// Neither the name of the project's author nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//


#import <UIKit/UIKit.h>
#import "BeamMusicPlayerDelegate.h"
#import "BeamMusicPlayerDataSource.h"
#import "OBSlider.h"

/**
 * The Music Player component. This is a drop-in view controller and provides the UI for a music player.
 * It does not actually play music, just visualize music that is played somewhere else. The data to display
 * is provided using the datasource property, events can be intercepted using the delegate-property.
 */
@interface BeamMusicPlayerViewController : UIViewController<OBSliderDelegate>

@property (nonatomic,weak) id<BeamMusicPlayerDelegate> delegate;
@property (nonatomic,weak) id<BeamMusicPlayerDataSource> dataSource;

// Public API methods go here.

@property (nonatomic) NSUInteger currentTrack; // The index of the currently set track
@property (nonatomic,readonly) BOOL playing; // Whether the player is in play-state
@property (nonatomic,readonly) CGFloat currentPlaybackPosition; // The Current Playback position in seconds
@property (nonatomic) CGFloat volume; // The Volume of the player

/**
 * Reloads data from the data source and updates the player. If the player is currently playing, the playback is stopped.
 */
-(void)reloadData;



/**
 * Seeks to the position in seconds specified.
 */
//-(void)seekToPosition:(CGFloat)position;

/**
 * Prepares the player: 
 *
 * Loads the first track using the information provided by the BeamMusicPlayerDataSource and displays it. 
 */
-(void)preparePlayer;

/**
 * Starts playback. If the player is already playing, this method does nothing except wasting some cycles.
 */
-(void)play;

/**
 * Starts playing the specified track. If the track is already playing, this method does nothing.
 */
//-(void)playTrack:(NSUInteger)track;

/**
 * Pauses the player. If the player is already paused, this method does nothing except generating some heat.
 */
-(void)pause;

/**
 * Skips to the next track. 
 *
 * If there is no next track, this method does nothing, if there is, it skips one track forward and informs the delegate. In case the BeamMusicPlayerDelegate implements the musicPlayer:shouldChangeTrack: method and returns NO, the track is not changed.
 */
-(void)next;

/**
 * Skips to the previous track. 
 *
 * If there is no previous track, i.e. the current track number is 0, this method does nothing, if there is, it skips one track backward and informs the delegate. In case the BeamMusicPlayerDelegate implements the musicPlayer:shouldChangeTrack: method and returns NO, the track is not changed.
 */
-(void)previous;

-(IBAction)nextAction:(id)sender;
-(IBAction)playAction:(id)sender;
-(IBAction)sliderValueChanged:(id)slider;

@end
