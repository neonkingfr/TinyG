/*
 * canonical_machine.h - rs274/ngc canonical machining functions
 * Part of TinyG
 *
 * This code is a loose implementation of Kramer, Proctor and Messina's
 * canonical machining functions as described in the NIST RS274/NGC v3
 * Sections of this code are adapted from Simen Svale Skogsrud's grbl
 * 
 * Copyright (c) 2010 Alden S Hart, Jr.
 * Portions copyright (c) 2009 Simen Svale Skogsrud
 *
 * TinyG is free software: you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License as published by the Free Software 
 * Foundation, either version 3 of the License, or (at your option) any later 
 * version.
 *
 * TinyG is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with TinyG  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef canonical_machine_h
#define canonical_machine_h

//--- helper functions for canonical machining functions---//
double _to_millimeters(double value);
double cm_get_position(uint8_t axis);
uint8_t cm_get_next_action(void);
uint8_t cm_get_motion_mode(void);
void cm_set_position(double x, double y, double z);
void cm_set_target(double x, double y, double z);
void cm_set_offset(double i, double j, double k);
void cm_set_radius(double r);

/*--- canonical machining functions ---*/
void cm_init_canon(void);					// init canonical machine

uint8_t cm_set_traverse_rate(double rate);		// (no corresponding G code)
uint8_t cm_straight_traverse(double x, double y, double z);	// G0
uint8_t cm_straight_feed(double x, double y, double z);		// G1
uint8_t cm_arc_feed(double x, double y, double z, 			// G2, G3
					double i, double j, double k,
					double radius, uint8_t motion_mode);

uint8_t cm_comment(char *comment);					// comment handler (null)
uint8_t cm_message(char *message);					// send message to console
uint8_t cm_select_plane(uint8_t plane);
uint8_t cm_set_inverse_feed_rate_mode(uint8_t mode); // T = inverse feed rate
uint8_t cm_set_feed_rate(double rate);				// F parameter
uint8_t cm_select_tool(uint8_t tool);				// T parameter
uint8_t cm_change_tool(uint8_t tool);				// M6, T
uint8_t cm_set_spindle_speed(double speed);			// S parameter
uint8_t cm_start_spindle_clockwise(void);			// M3
uint8_t cm_start_spindle_counterclockwise(void);	// M4
uint8_t cm_stop_spindle_turning(void);				// M5
uint8_t cm_return_to_home(void);					// G28, G30
uint8_t cm_set_origin_offsets(double x, double y, double z); // G92
uint8_t cm_use_length_units(uint8_t inches_mode);	// G20, G21
uint8_t cm_stop(void);								// M0, M1
uint8_t cm_start(void);								// (re)enable steppers
uint8_t cm_message(char *);							// send message to console
uint8_t cm_dwell(double seconds);					// G4, P parameter
uint8_t cm_set_distance_mode(uint8_t absolute_mode);// G90, G91 (abs/incr motion)

uint8_t cm_optional_program_stop(void);				// M1
uint8_t cm_program_stop(void);						// M0
uint8_t cm_program_end(void);						// M2


#endif

