GAME AGE OF WAR

Flappy Bird là một trò chơi điện tử do Nguyễn Hà Đông, một lập trình viên người Việt Nam, phát triển và được phát hành bởi dotGEARS vào năm 2013. Trò chơi có lối chơi đơn giản nhưng đầy thử thách, yêu cầu người chơi điều khiển một chú chim bay qua các ống màu xanh mà không va chạm1. Ban đầu, Flappy Bird không gây chú ý, nhưng đến đầu năm 2014, nó bất ngờ trở thành hiện tượng toàn cầu, đứng đầu bảng xếp hạng ứng dụng trên App Store và Google Play. Tuy nhiên, do áp lực từ sự nổi tiếng và những tác động không mong muốn, Nguyễn Hà Đông đã quyết định gỡ bỏ trò chơi vào tháng 2 năm 20141. Sự biến mất đột ngột của Flappy Bird khiến cộng đồng game xôn xao, và nhiều trò chơi tương tự đã xuất hiện sau đó.
Là 1 biến thể của flappy bird,Age Of War hứa hẹn sẽ đem lại trải nghiệm mới mẻ và vẫn giữ nguyên gameplay cổ điển

Mô tả về cách chơi:

Age Of War là một trò chơi điện tử có cách chơi đơn giản nhưng đầy thách thức. Người chơi điều khiển một máy bay bằng cách nhấn vào màn hình để giúp nó bay lên. Nếu không nhấn, máy bay sẽ rơi xuống do trọng lực.

Mục tiêu là đưa máy bay bay qua các khoảng trống giữa các ống màu xanh mà không va chạm vào chúng. Mỗi lần vượt qua một ống, người chơi sẽ được tính một điểm. Trò chơi kết thúc ngay lập tức nếu máy bay chạm vào ống hoặc rơi xuống đất.

1. Tổng quan về cơ chế chơi của Age Of War
Trò chơi thuộc thể loại arcade với cách điều khiển chỉ có một thao tác: chạm màn hình để khiến máy bay bay lên. Khi không chạm, máy bay sẽ rơi xuống do lực hấp dẫn. Người chơi phải điều chỉnh nhịp độ chạm để giúp máy bay bay qua các khe hở giữa cột ống nước mà không va vào chúng

2. Xử lý va chạm trong trò chơi
2.1. Phát hiện va chạm
Age Of War sử dụng cơ chế phát hiện va chạm dựa trên hình chữ nhật bao quanh đối tượng (bounding box collision detection) để xác định xem máy bay đã va phải một vật thể nào chưa. Cụ thể, có ba loại va chạm mà trò chơi phải xử lý:

Va chạm với các đường ống: Mỗi cặp ống được lập trình như hai hình chữ nhật – một ở trên và một ở dưới – với khoảng trống đủ cho chim bay qua. Nếu bất kỳ phần nào của hình chữ nhật bao quanh máy bay chồng lên hình chữ nhật của đường ống, trò chơi coi như đã có va chạm và lập tức kết thúc.

Va chạm với mặt đất: Dưới cùng màn hình là khoảng không vô định hoạt động như một không gian nguy hiểm. Nếu ,máy bay rơi xuống thấp hơn một ngưỡng nhất định, nó sẽ chạm không gian nguy hiểm đó và trò chơi kết thúc ngay lập tức.

Va chạm với giới hạn phía trên màn hình: Nếu người chơi liên tục chạm khiến máy bay bay quá cao, nó sẽ đụng vào giới hạn trên cùng của màn hình, cũng gây ra kết thúc trò chơi.

2.2. Xử lý khi xảy ra va chạm
Mỗi khi phát hiện va chạm, trò chơi sẽ thực hiện các bước sau:

Kích hoạt hiệu ứng kết thúc:Ngăn chặn máy bay tiếp tục di chuyển và lập tức out game.

Ghi lại điểm số : Sau mỗi lần vượt ống điểm sẽ được tăng hiển thị trên màn hình

2.3. Tối ưu hóa xử lý va chạm
Một số bản sao của Age Of War và các trò chơi tương tự đã áp dụng phương pháp phát hiện va chạm dựa trên pixel (pixel-perfect collision detection) thay vì chỉ dựa vào hình chữ nhật. Điều này giúp cải thiện độ chính xác, đặc biệt là khi hình dạng của máy bay không phải là hình hộp đơn giản.

2.4. Ảnh hưởng của cơ chế va chạm đến trải nghiệm người chơi
Do xử lý va chạm mang tính tức thời và không cho phép sai sót, Age Of War trở thành một trò chơi cực kỳ thách thức. Chỉ cần một khoảnh khắc mất tập trung, người chơi sẽ thất bại ngay lập tức. Chính điều này khiến game trở nên gây nghiện, thúc đẩy người chơi thử lại nhiều lần để cải thiện thành tích.

Các tài nguyên hiển thị trong game:

![background](https://github.com/user-attachments/assets/948c4a46-98ed-4cbf-82c9-122e2e3cba54):
Background của trò chơi,mang lại cảm giác đầy nguy hiểm thách thức

![bird](https://github.com/user-attachments/assets/8c658637-3ebb-4e0c-be2d-245b4bfa8cbc)
Nhân vật chính đòi hỏi sự khéo léo của người chơi để vượt qua mọi cản trở,đến nơi an toàn

![pipe](https://github.com/user-attachments/assets/defed177-bfda-4cc4-b432-2ba1bd2ad078)
Vật cản duy nhất cần né tránh

Nhạc nền được lấy từ: https://pixabay.com/vi/music/search/nh%E1%BA%A1c%20chi%E1%BA%BFn%20tranh%20ho%C3%A0nh%20tr%C3%A1ng/




