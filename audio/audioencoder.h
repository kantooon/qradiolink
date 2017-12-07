// Written by Adrian Musceac YO8RZZ , started August 2014.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef AUDIOENCODER_H
#define AUDIOENCODER_H

#include <QDebug>
#include <opus/opus.h>
#include <codec2/codec2.h>
extern "C" {
#include <gsm/gsm.h>
}
#include "ext/agc.h"

class AudioEncoder
{
public:
    AudioEncoder();
    ~AudioEncoder();
    unsigned char *encode_opus(short *audiobuffer, int audiobuffersize, int &encoded_size);
    short *decode_opus(unsigned char *audiobuffer, int data_length, int &samples);
    unsigned char* encode_codec2(short *audiobuffer, int audiobuffersize, int &length);
    short* decode_codec2(unsigned char *audiobuffer, int audiobuffersize, int &samples);
    unsigned char* encode_codec2_700(short *audiobuffer, int audiobuffersize, int &length);
    short* decode_codec2_700(unsigned char *audiobuffer, int audiobuffersize, int &samples);
    unsigned char* encode_gsm(short *audiobuffer, int audiobuffersize, int &length);
    short* decode_gsm(unsigned char *audiobuffer, int data_length, int &samples);


private:
    OpusEncoder *_enc;
    OpusDecoder *_dec;
    struct CODEC2 *_codec2;
    struct CODEC2 *_codec2_700;
    struct gsm_state *_gsm;
    hvdi::agc_st *_agc;
};

#endif // AUDIOENCODER_H
