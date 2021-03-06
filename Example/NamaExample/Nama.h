#pragma once

#include <vector>
#include <memory>

class CCameraDS;
namespace NE
{
	class Nama
	{
		enum MODE
		{
			PROP,
			LANDMARK
		};
	public:
		Nama();
		void Init(const int width=1280, const int height=720);

		void SwitchRenderMode();
		void SwitchBeauty();
		void PreBundle();
		void NextBundle();

		void SwitchFilter();
		void UpdateColorLevel(const double delta);
		void UpdateBlurLevel(const double delta);
		void UpdateCheekThinning(const double delta);
		void UpdateEyeEnlarging(const double delta);

		std::tr1::shared_ptr<unsigned char> NextFrame();

	private:
		void CreateBundle();
		void CreateBundle(const int idx);

		void DrawLandmarks(std::tr1::shared_ptr<unsigned char> frame);
		void DrawPoint(std::tr1::shared_ptr<unsigned char> frame, int x, int y, unsigned char r = 255, unsigned char g = 0, unsigned char b = 0);

	private:
		int m_frameID;
		std::tr1::shared_ptr<CCameraDS> m_cap;

		int m_curBundleIdx;

		MODE m_mode;
		bool m_isBeautyOn;

		std::vector<int> m_propHandles;
		int m_beautyHandles;

		int m_frameWidth, m_frameHeight;

	private:
		int m_curFilterIdx;
		double m_curColorLevel;
		double m_curBlurLevel;
		double m_curCheekThinning;
		double m_curEyeEnlarging;

		static std::string _filters[6];
	};
}