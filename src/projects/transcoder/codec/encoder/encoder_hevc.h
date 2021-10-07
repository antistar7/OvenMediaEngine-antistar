//==============================================================================
//
//  Transcode
//
//  Created by Kwon Keuk Han
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "../../transcoder_encoder.h"

class EncoderHEVC : public TranscodeEncoder
{
public:
	~EncoderHEVC();

	AVCodecID GetCodecID() const noexcept override
	{
		return AV_CODEC_ID_H265;
	}

	int GetPixelFormat() const noexcept override
	{
		return AV_PIX_FMT_YUV420P;
	}

	bool Configure(std::shared_ptr<TranscodeContext> context) override;

	std::shared_ptr<MediaPacket> RecvBuffer(TranscodeResult *result) override;

	void ThreadEncode() override;

	void Stop() override;
};
