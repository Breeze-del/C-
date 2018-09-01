// Resource.cpp: implementation of the CResource class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "stdio.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IplImage* CResource::m_peashooter[4] =
{
	cvLoadImage(".\\img\\model\\Õ„∂π…‰ ÷\\0.png"),
	cvLoadImage(".\\img\\model\\Õ„∂π…‰ ÷\\1.png"),
	cvLoadImage(".\\img\\model\\Õ„∂π…‰ ÷\\2.png"),
	cvLoadImage(".\\img\\model\\Õ„∂π…‰ ÷\\3.png")
};
IplImage* CResource::m_sunflower[3] =
{
	cvLoadImage(".\\img\\model\\œÚ»’ø˚\\0.png"),
	cvLoadImage(".\\img\\model\\œÚ»’ø˚\\1.png"),
	cvLoadImage(".\\img\\model\\œÚ»’ø˚\\2.png")
};
IplImage* CResource::m_iceshooter[3] =
{
	cvLoadImage(".\\img\\model\\∫Æ±˘…‰ ÷\\0.png"),
	cvLoadImage(".\\img\\model\\∫Æ±˘…‰ ÷\\1.png"),
	cvLoadImage(".\\img\\model\\∫Æ±˘…‰ ÷\\2.png")
};

IplImage* CResource::m_pumpkin[4] =
{
	cvLoadImage(".\\img\\model\\Œ—πœ\\0.png"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\1.png"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\2.png"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\3.png")
};
IplImage* CResource::m_pumpkin_attack[4] =
{
	cvLoadImage(".\\img\\model\\Œ—πœ\\attack\\1.jpg"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\attack\\2.jpg"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\attack\\3.jpg"),
	cvLoadImage(".\\img\\model\\Œ—πœ\\attack\\4.jpg")
};
IplImage* CResource::m_nut[4] =
{
	cvLoadImage(".\\img\\model\\º·π˚\\0.png"),
	cvLoadImage(".\\img\\model\\º·π˚\\1.png"),
	cvLoadImage(".\\img\\model\\º·π˚\\2.png"),
	cvLoadImage(".\\img\\model\\º·π˚\\3.png")
};
IplImage* CResource::m_cherrybomb[6] =
{
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\0.png"),
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\1.png"),
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\2.png"),
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\3.png"),
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\4.png"),
	cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\5.png")
};
IplImage* CResource::m_hatZom_move[11] =
{
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\1.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\2.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\3.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\4.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\5.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\6.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\7.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\8.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\9.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\10.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\move\\11.jpg")
};
IplImage* CResource::m_hatZom_attack[6] =
{
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\1.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\2.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\3.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\4.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\5.jpg"),
	cvLoadImage(".\\img\\model\\√±◊”Ω© ¨\\attack\\6.jpg")
};
IplImage* CResource::m_normalZom_move[6] =
{
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\1.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\2.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\3.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\4.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\5.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\move\\6.jpg")
};
IplImage* CResource::m_normalZom_attack[6] =
{
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\1.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\2.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\3.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\4.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\5.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\attack\\6.jpg")
};
IplImage* CResource::m_normalZom_bomb[10] =
{
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\1.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\2.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\3.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\4.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\5.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\6.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\7.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\8.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\9.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\bomb\\10.jpg")
};
IplImage* CResource::m_normalZom_dead[7] =
{
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\1.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\2.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\3.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\4.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\5.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\6.jpg"),
	cvLoadImage(".\\img\\model\\∆’Õ®Ω© ¨\\dead\\body\\7.jpg")
};
IplImage* CResource::m_doorZom_move[9] =
{
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\1.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\2.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\3.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\4.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\5.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\6.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\7.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\8.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\move\\9.jpg")
};
IplImage* CResource::m_doorZom_attack[6] =
{
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\1.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\2.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\3.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\4.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\5.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙√≈Ω© ¨\\attack\\6.jpg")
};
IplImage* CResource::m_drumZom_move[6] =
{
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\1.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\2.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\3.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\4.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\5.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\move\\6.jpg")
};
IplImage* CResource::m_drumlZom_attack[6] =
{
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\1.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\2.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\3.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\4.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\5.jpg"),
	cvLoadImage(".\\img\\model\\Ã˙Õ∞Ω© ¨\\attack\\6.jpg")
};
IplImage* CResource::m_cards[7] =
{
	cvLoadImage(".\\img\\card\\∫Æ±˘…‰ ÷_ø®.png"),
	cvLoadImage(".\\img\\card\\º·π˚_ø®.png"),
	cvLoadImage(".\\img\\card\\Õ„∂π…‰ ÷_ø®.png"),
	cvLoadImage(".\\img\\card\\Œ—πœ_ø®.png"),
	cvLoadImage(".\\img\\card\\œÚ»’ø˚_ø®.png"),
	cvLoadImage(".\\img\\card\\”£Ã“’®µØ_ø®.png"),
	cvLoadImage(".\\img\\card\\ ≥»Àª®_ø®.png")
};

IplImage* CResource::m_bg = cvLoadImage(".\\img\\bg\\GameBg.png");
IplImage* CResource::m_ball = cvLoadImage(".\\img\\model\\ball.png");
IplImage* CResource::m_iceball = cvLoadImage(".\\img\\model\\iceball.png");
IplImage* CResource::m_sun = cvLoadImage(".\\img\\model\\sun.png");
IplImage* CResource::m_scoop = cvLoadImage(".\\img\\model\\≤˘◊”.png");
IplImage* CResource::m_peashooter_write = cvLoadImage(".\\img\\model\\Õ„∂π…‰ ÷\\∞◊.png");
IplImage* CResource::m_sunflower_write = cvLoadImage(".\\img\\model\\œÚ»’ø˚\\∞◊.png");
IplImage* CResource::m_iceshooter_write = cvLoadImage(".\\img\\model\\∫Æ±˘…‰ ÷\\∞◊.png");
IplImage* CResource::m_pumpkin_write = cvLoadImage(".\\img\\model\\Œ—πœ\\∞◊.png");
IplImage* CResource::m_nut_write = cvLoadImage(".\\img\\model\\º·π˚\\∞◊.png");
IplImage* CResource::m_cherrybomb_write = cvLoadImage(".\\img\\model\\”£Ã“’®µØ\\∞◊.png");
IplImage* CResource::m_startimg = cvLoadImage(".\\img\\bg\\Start.png");
IplImage* CResource::m_endimg = cvLoadImage(".\\img\\bg\\end.png");
IplImage* CResource::m_warning = cvLoadImage(".\\img\\bg\\warning.png");
IplImage* CResource::m_prepare = cvLoadImage(".\\img\\bg\\prepare.png");
CResource::CResource()
{

}

CResource::~CResource()
{
	cvReleaseImage(&m_ball);
	cvReleaseImage(&m_iceball);
	cvReleaseImage(&m_sun);
	cvReleaseImage(&m_bg);
	cvReleaseImage(&m_scoop);
	cvReleaseImage(&m_peashooter_write);
	cvReleaseImage(&m_sunflower_write);
	cvReleaseImage(&m_iceshooter_write);
	cvReleaseImage(&m_pumpkin_write);
	cvReleaseImage(&m_nut_write);
	cvReleaseImage(&m_cherrybomb_write);
	cvReleaseImage(&m_startimg);
	cvReleaseImage(&m_endimg);
	Clear(m_cards, 6);
	Clear(m_peashooter, 4);
	Clear(m_sunflower, 3);
	Clear(m_iceshooter, 3);
	Clear(m_pumpkin, 4);
	Clear(m_pumpkin_attack, 4);
	Clear(m_nut, 4);
	Clear(m_cherrybomb, 6);
	Clear(m_hatZom_move, 11);
	Clear(m_hatZom_attack, 6);
	Clear(m_doorZom_move, 9);
	Clear(m_doorZom_attack, 6);
	Clear(m_drumZom_move, 6);
	Clear(m_drumlZom_attack, 6);
	Clear(m_normalZom_move, 6);
	Clear(m_normalZom_dead, 7);
	Clear(m_normalZom_attack, 6);
	Clear(m_normalZom_bomb, 10);
}
void CResource::LoadImg(IplImage *in[], vector <IplImage* >& out, int num) {
	for (int i = 0; i < num; i++) {
		out.push_back(in[i]);
	}
}

void CResource::Clear(IplImage *img[], int num)
{
	for (int i = 0; i < num; i++) {
		cvReleaseImage(&img[i]);
	}
}
