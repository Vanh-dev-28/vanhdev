Flappy Bird là một trò chơi điện tử do Nguyễn Hà Đông, một lập trình viên người Việt Nam, phát triển và được phát hành bởi dotGEARS vào năm 2013. Trò chơi có lối chơi đơn giản nhưng đầy thử thách, yêu cầu người chơi điều khiển một chú chim bay qua các ống màu xanh mà không va chạm. Ban đầu, Flappy Bird không gây chú ý, nhưng đến đầu năm 2014, nó bất ngờ trở thành hiện tượng toàn cầu, đứng đầu bảng xếp hạng ứng dụng trên App Store và Google Play. Tuy nhiên, do áp lực từ sự nổi tiếng và những tác động không mong muốn, Nguyễn Hà Đông đã quyết định gỡ bỏ trò chơi vào tháng 2 năm 2014. Sự biến mất đột ngột của Flappy Bird khiến cộng đồng game xôn xao, và nhiều trò chơi tương tự đã xuất hiện sau đó.

Lấy ý tưởng từ game Flappy Bird,game Age of War mô phỏng quá trình máy bay chiến đấu phải vượt qua các vật cản để có thể sống sót,với bối cảnh chiến tranh ác liệt cùng với sự nguy hiểm của chiến trường,Age of War đòi hỏi sự khéo léo,phản xạ nhanh đưa máy bay vượt qua hiểm nguy trở về nơi an toàn.

🎮 Cách chơi:
Flappy Bird là một trò chơi điện tử có cách chơi đơn giản nhưng đầy thách thức. Người chơi điều khiển một chiếc máy bay chiến đấu bằng cách nhấn vào màn hình để giúp nó bay lên. Nếu không nhấn, nó sẽ rơi xuống do trọng lực.

Mục tiêu là đưa máy bay bay qua các khoảng trống giữa các ống màu đen xám mà không va chạm vào chúng. Mỗi lần vượt qua một ống, người chơi sẽ được tính một điểm. Trò chơi kết thúc ngay lập tức nếu chim chạm vào ống hoặc rơi xuống đất.

Mô tả về các đối tượng trong trò chơi

![image](https://github.com/user-attachments/assets/33bd5cc6-564d-4b53-a1be-29e51f1e7a77)

: là nhân vật chính của trò chơi,người chơi cần phải điều khiển bằng cách nhấn space để máy bay bay lên,nếu không máy bay sẽ rơi xuống bởi tác dụng của trọng lực.

![image](https://github.com/user-attachments/assets/ec7533ba-3a82-4c1b-b3bc-9f36b48bf029)
: Mối nguy hiểm của nhân vật chính,khi máy bay va chạm với ống nước sẽ lập tức bị rớt xuống,người chơi sẽ thua cuộc.

Mô tả game play, xử lý va chạm:
1.Trò chơi thuộc thể loại arcade với cách điều khiển chỉ có một thao tác: chạm màn hình để khiến máy bay bay lên. Khi không chạm, máy bay sẽ rơi xuống do lực hấp dẫn. Người chơi phải điều chỉnh nhịp độ chạm để giúp máy bay bay qua các khe hở giữa cột ống nước màu xám mà không va vào chúng.
2. Xử lý va chạm trong trò chơi

2.1. Phát hiện va chạm

Age of War sử dụng cơ chế phát hiện va chạm dựa trên hình chữ nhật bao quanh đối tượng (bounding box collision detection) để xác định xem máy bay đã va phải một vật thể nào chưa. Cụ thể, có ba loại va chạm mà trò chơi phải xử lý:

Va chạm với các đường ống: Mỗi cặp ống được lập trình như hai hình chữ nhật – một ở trên và một ở dưới – với khoảng trống đủ cho máy bay bay qua. Nếu bất kỳ phần nào của hình chữ nhật bao quanh máy bay chồng lên hình chữ nhật của đường ống, trò chơi coi như đã có va chạm và lập tức kết thúc.


Va chạm với mặt đất: Dưới cùng màn hình là nền đất (ground) hoạt động như một bề mặt cố định. Nếu máy bay rơi xuống thấp hơn một ngưỡng nhất định, nó sẽ chạm đất và trò chơi kết thúc ngay lập tức.


Va chạm với giới hạn phía trên màn hình: Nếu người chơi liên tục chạm khiến máy bay bay quá cao, nó sẽ đụng vào giới hạn trên cùng của màn hình, cũng gây ra kết thúc trò chơi.

2.2. Xử lý khi xảy ra va chạm: Game sẽ tự động kết thúc và thoát ra khỏi màn hình khi xảy ra va chạm


2.3:Ảnh hưởng của cơ chế va chạm đến trải nghiệm người chơi

Do xử lý va chạm mang tính tức thời và không cho phép sai sót, Age Of War trở thành một trò chơi cực kỳ thách thức. Chỉ cần một khoảnh khắc mất tập trung, người chơi sẽ thất bại ngay lập tức. Chính điều này khiến game trở nên gây nghiện, thúc đẩy người chơi thử lại nhiều lần để cải thiện thành tích.

Nguồn dẫn tham khảo tạo nên game:

-Các tấm ảnh và background được tạo nên từ AI bằng văn bản.

-Link googleDrive mô tả chi tiết tất cả source code của game:https://drive.google.com/file/d/1YWGQCll5cGyTArIwudYxjXwXNNYIwuR5/view?fbclid=IwY2xjawJ4ra1leHRuA2FlbQIxMABicmlkETF0UlhmWW53NHp2TVl3MHoyAR4DPmepu0as95Q-3Sn6qx_l2b_ZPvOeE0moZPKKV0_V-INTMBrIkGJF8omg7g_aem_narHeFR2dOypRMxe3CrAPQ

Hãy cùng tham gia vào thế giới Age Of War-nơi đem lại cho bạn sự thử thách,tính kiên nhẫn và phản xạ nhanh chóng.Hãy đưa chiếc máy bay của chiến tranh về nơi an toàn!
