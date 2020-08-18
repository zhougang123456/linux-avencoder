extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
};
#define DEFAULT_FRAME_RATE 25

class AvEncoder
{
public:
    AvEncoder();
    ~AvEncoder();
    bool init(char* codec_name, int width, int height);
    void encode(unsigned char* buffer);
private:
    bool rgba_to_yuv420(AVFrame* frmArgb, AVFrame* frm420p);
    AVCodec* codec;
    AVCodecContext* context;
    AVFrame* frmArgb;
    AVFrame* frm420p;
    AVPacket* pkt;
    SwsContext* sws;
};

