#ifndef ListeningSocket_H
#define ListeningSocket_H

#include "BindingSocket.hpp"


namespace HDE  {
    class ListeningSocket : public BindingSocket{
        private:
            int backlog;
            int listening;
        public:

            ListeningSocket(int domain, int service, int protocal, u_short port , u_long localIP, int backlog);
            void start_listening();
            
    };
}





#endif // ListeningSocket_H



























