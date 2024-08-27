/*
Q2.	클라이언트 영역에 마우스 클릭 시 도형을 생성한다.
	도형은 사각형, 원, 별이 랜덤하게 생성되도록 한다.

	1. 생성된 도형은 임의 방향으로 회전하면서 이동한다.

	2. 클라이언트 영역 외각에서 반사되도록 한다.

	3. 모드 설정
		1. 반사
			다른 오브젝트와 부딪치면 튕겨 나간다
			이동속도나 크기 속성 반영

		2. 합체
			상성 관계에 따라 다른 오브젝트를 만나면 합체해서 커지게 한다

		3. 분열
			상성 관계에 따라 다른 오브젝트를 만나면 분열해서 작아지게 한다.

		# 상성관계
			별 > 사각형 > 원 > 별

		4. 일정 크기 이상 또는 일정 크기 이하는 사라지도록 한다.



	CObject
	{
		protected:
			좌표, 이동 스피드, 이동 방향, 타입 (원, 별, 사각형)

		public:
			virtual void Update() = 0;
			virtual void Draw() = 0;
			virtual BOOL Collision() = 0;
			etc...
	};

	class CCircle : public CObject
	{
		private :
			반지름 ....

		public :
			void Update() override;
			void Draw() override;
			BOOL Collision() override;
	};
*/