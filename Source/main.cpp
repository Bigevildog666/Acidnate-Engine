#include <cstdio>

#include <volk.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

int main() {

	VkResult r;
	uint32_t version;

	r = volkInitialize();

	if (r != VK_SUCCESS)
	{
		return -1;
	}
	version = volkGetInstanceVersion();
	printf("Vulkan version %d.%d.%d initialized.\n",
            VK_VERSION_MAJOR(version),
            VK_VERSION_MINOR(version),
            VK_VERSION_PATCH(version));
	
	return 0; 
}