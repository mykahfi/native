#include "ui.h"
#include "ui_context.h"
#include "gfx/texture.h"
#include "gfx_es2/draw_buffer.h"
#include "gfx_es2/glsl_program.h"

void UIContext::Begin()
{
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (uishader_)
		glsl_bind(uishader_);
	if (uitexture_)
		uitexture_->Bind(0);

	UIBegin();
	/*
	if (uidrawbuffer_ && uishader_)
		uidrawbuffer_->Begin();
	if (uidrawbufferTop_ && uishader_)
		uidrawbufferTop_->Begin();*/
}

void UIContext::End() 
{
	UIEnd();
	if (uidrawbuffer_)
	{
		uidrawbuffer_->End();
		if (uishader_)
			uidrawbuffer_->Flush(uishader_);
	}
	if (uidrawbufferTop_)
	{
		uidrawbuffer_->End();
		if (uishader_)
			uidrawbufferTop_->Flush(uishader_);
	}
}