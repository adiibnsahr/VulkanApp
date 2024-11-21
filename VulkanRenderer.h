#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "Utilities.h"

class VulkanRenderer
{
public:
	VulkanRenderer();

	int init(GLFWwindow* newWindow);
	void cleanup();

	~VulkanRenderer();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;
	struct 
	{
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	}mainDevice;
	VkQueue graphicsQueue;

	// Vulkan Functions
	void createInstance();
	void createLogicalDevice();

	// Get functions
	void getPhysicalDevice();

	// - Support function
	// -- Checker functions
	bool checkInstanceExtensionSupport(std::vector<const char*>* checkExtension);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	// -- Getter functions
	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};

