#include <tremor/ivorbiscodec.h>
#include <tremor/ivorbisfile.h>
#include "gui/sounds/SoundDecoder.hpp"

class OggDecoder : public SoundDecoder {
public:
    OggDecoder(const char *filepath);

    OggDecoder(const uint8_t *snd, int32_t len);

    virtual ~OggDecoder();

    int32_t Rewind();

    int32_t Read(uint8_t *buffer, int32_t buffer_size, int32_t pos);

protected:
    void OpenFile();

    OggVorbis_File ogg_file;
    vorbis_info *ogg_info;
};
